#include "test.h"
#include "cube3d.h"

void	test_valid_file(void)
{
	assert(!valid_file("./"));
	assert(!valid_file("./src/main.c"));
	assert(!valid_file("./src/parser"));
	assert(!valid_file("./src/parser/bonjour"));
	assert(!valid_file("./.cub"));
	assert(!valid_file("./tests/assets/no_access.cub"));
	assert(valid_file("./maps/simple.cub"));
}

int	main(void)
{
	t_test_config	config;
	t_test			tests[] = {
		{&test_valid_file, "parser::test_valid_file"},
		{NULL, NULL}
	};
	init_test_config(&config);

	run_tests(tests, &config);
	return (0);
}
