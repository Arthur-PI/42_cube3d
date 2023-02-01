#include "test.h"
#include "cube3d.h"

void	test_valid_file(void)
{
	assert(!valid_file("./"));
	assert(!valid_file("./src/main.c"));
	assert(!valid_file("./src/parser"));
	assert(!valid_file("./src/parser/bonjour"));
	assert(!valid_file("./.cub"));
	assert(!valid_file("/etc/shadow"));
	remove("/tmp/test.cub");
	open("/tmp/test.cub", O_CREAT, 0200);
	assert(!valid_file("/tmp/test.cub"));
	remove("/tmp/test.cub");
	mkdir("/tmp/dir.cub", 0700);
	assert(!valid_file("/tmp/dir.cub"));
	rmdir("/tmp/dir.cub");
	assert(valid_file("./maps/simple.cub"));
}

void	check_game(t_game *game, uint h, uint w, int pos[2])
{
	assert(game != NULL);
	// printf("Dimensions: (%d,%d)\n", game->map->height, game->map->width);
	assert(game->map->height == h);
	assert(game->map->width == w);
	// printf("Pos: (%d,%d)\n", game->map->player->pos[0], game->map->player->pos[1]);
	assert(game->map->player->pos[0] == pos[0]);
	assert(game->map->player->pos[1] == pos[1]);
}

void	test_parse_file(void)
{
	t_game	*game;

	game = parse_file("./tests/assets/maps/map1.cub");
	check_game(game, 5, 6, (int[2]){4, 3});
	game = parse_file("./tests/assets/maps/map2.cub");
	check_game(game, 5, 6, (int[2]){4, 3});
}

int	main(void)
{
	t_test_config	config;
	t_test			tests[] = {
		{&test_valid_file, "parser::test_valid_file"},
		{&test_parse_file, "parser::test_parse_file"},
		{NULL, NULL}
	};
	init_test_config(&config);

	run_tests(tests, &config);
	return (0);
}
