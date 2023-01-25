#include "test.h"

void	test1(void)
{
	write(1, "test\n", 5);
	assert(1 == 1);
}

void	test2(void)
{
	write(1, "test\n", 5);
	usleep(214);
	assert(1 == 1);
}

void	test3(void)
{
	write(1, "test\n", 5);
	assert(2 == 2);
}

void	test4(void)
{
	char *s1 = "Hello";
	char *s2 = "Hello";

	assert_str(s1, s2);
}

void	test5(void)
{
	char *s1 = "Lonjour";
}

void	test6(void)
{
	while (1) {continue ;}
}

int	main(void)
{
	t_test	tests[] = {
		{&test1, "main::test1"},
		{&test2, "main::test2"},
		{&test3, "main::test3"},
		{&test4, "main::test4"},
		{&test5, "main::test5"},
		{&test6, "main::test6"},
		{NULL, NULL}
	};
	run_tests(tests);
	return (0);
}
