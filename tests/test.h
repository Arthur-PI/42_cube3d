#ifndef TEST_H
# define TEST_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <assert.h>
# include <sys/time.h>
# include <signal.h>

# define RESET	"\033[0;0m"
# define BLACK	"\033[0;30m"
# define RED	"\033[0;31m"
# define GREEN	"\033[0;32m"
# define YELLOW	"\033[0;33m"
# define BLUE	"\033[0;34m"
# define PURPLE	"\033[0;35m"
# define CYAN	"\033[0;36m"
# define WHITE	"\033[0;37m"

# define assert_str(s1, s2) \
	(strcmp(s1, s2) != 0 ? __assert_str_rtn(s1, s2, __FILE__, __func__, __LINE__) : (void)0)

typedef struct timeval t_timeval;

typedef struct	s_test
{
	void	(*f)(void);
	char	*name;
}				t_test;

void	run_tests(t_test tests[]);
void	__assert_str_rtn(const char *s1, const char *s2, const char *file, const char *function, int line);

#endif
