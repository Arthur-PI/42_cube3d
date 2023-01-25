#include "../test.h"

void	__assert_str_rtn(const char *s1, const char *s2, const char *file, const char *function, int line)
{
	fprintf(stderr, "Assertion failed: (\"%s\" != \"%s\"), function %s, file %s, line %d.",
		s1, s2, function, file, line);
	exit(2);
}

void	print_pipe(int fd)
{
	int		ret;
	char	buf[512 + 1];

	do {
		ret = read(fd, buf, 512);
		buf[ret] = 0;
		printf("%s", buf);
	} while (ret != 0);
}

void	test_passed(char *name, double time)
{
	printf("\t%sPASS%s [% 6.2fs]\t\t%s%s%s\n", GREEN, RESET, time, BLUE, name, RESET);
}

void	test_failed(char *name, int stdout, int stderr, double time, int status)
{
	int		signal;
	char	*sig;

	sig = "";
	if (WIFSIGNALED(status)) {
		signal = WTERMSIG(status);
		if (signal == SIGSEGV)
			sig = "SIGSEGV";
		if (signal == SIGBUS)
			sig = "SIGBUS";
		if (signal == SIGPIPE)
			sig = "SIGPIPE";
		if (signal == SIGUSR1)
			sig = "TIMEOUT";
	}
	printf("\t%sFAIL%s [% 6.2fs]\t\t%s%s%s %s%s%s\n\n", RED, RESET, time, BLUE, name, RESET, RED, sig, RESET);
	printf("%s--- STDOUT:%s           \t\t%s%s%s %s---%s\n", RED, RESET, BLUE, name, RESET, RED, RESET);
	print_pipe(stdout);
	printf("\n%s--- STDERR:%s           \t\t%s%s%s %s---%s\n", RED, RESET, BLUE, name, RESET, RED, RESET);
	print_pipe(stderr);
	printf("\n%s---%s\n", RED, RESET);
}

void	child_test(void (*f)(void), int fd_out[2], int fd_err[2])
{
	close(fd_out[0]);
	close(fd_err[0]);
	dup2(fd_out[1], STDOUT_FILENO);
	dup2(fd_err[1], STDERR_FILENO);
	f();
	exit(0);
}

double timediff(t_timeval end, t_timeval start)
{
	double	diff;

	diff = ((end.tv_sec - start.tv_sec) * 1000 + ((double)(end.tv_usec - start.tv_usec)) / 1000);
	return (diff / 1000);
}

int	settimeout(int pid, uint timeout)
{
	int	pid2;
	
	pid2 = fork();
	if (pid2 == -1) exit(4);
	if (pid2 == 0) {
		sleep(timeout);
		kill(pid, SIGUSR1);
		exit(0);
	}
	return (pid2);
}

bool	launch_test(void (*f)(void), char *name, double *total_time)
{
	int				pid, status, timer_pid;
	int				fd_out[2], fd_err[2];
	double			elapsed;
	struct timeval 	start, end;
	
	if (pipe(fd_out) == -1) exit(1);
	if (pipe(fd_err) == -1) exit(2);
	gettimeofday(&start, NULL);
	pid = fork();
	if (pid == -1) exit(3);
	// Launch test function in a child process
	if (pid == 0)
		child_test(f, fd_out, fd_err);
	// Main process here because child exit
	close(fd_out[1]);
	close(fd_err[1]);
	timer_pid = settimeout(pid, 1);
	waitpid(pid, &status, 0);
	gettimeofday(&end, NULL);
	elapsed = timediff(end, start);
	*total_time += elapsed;
	if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
		test_passed(name, elapsed);
	else
		test_failed(name, fd_out[0], fd_err[0], elapsed, status);
	close(fd_out[0]);
	close(fd_err[0]);
	kill(timer_pid, SIGKILL);
	return (status != 0);
}

uint	nb_tests(t_test tests[])
{
	uint	i;

	i = 0;
	while (tests[i].f != NULL)
		i++;
	return (i);
}

void	run_tests(t_test tests[])
{
	uint	i, failed, nbtests;
	double	total_time;

	i = failed = total_time = 0;
	nbtests = nb_tests(tests);
	printf("    %sStarting%s %d tests\n", GREEN, RESET, nbtests);
	printf("------------\n");
	while (tests[i].f != NULL && failed == 0) {
		failed += launch_test(tests[i].f, tests[i].name, &total_time);
		i++;
	}
	if (failed)
		printf("%sCanceling due to test failure%s\n", RED, RESET);
	printf("------------\n");
	printf("    %sSummary%s [% 6.2fs] %d/%d tests run: %d %spassed%s, %d %sfailed%s\n",
		GREEN, RESET, total_time, i, nbtests, i - failed, GREEN, RESET, failed, RED, RESET);
}
