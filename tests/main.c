#include "test.h"
#include "cube3d.h"

static void	test_valid_file(void)
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

static void	check_game(t_game *game, uint h, uint w, int pos[2])
{
	assert(game != NULL);
	// printf("Dimensions: (%d,%d)\n", game->map->height, game->map->width);
	assert(game->map->height == h);
	assert(game->map->width == w);
	// printf("Pos: (%d,%d)\n", game->map->player->pos[0], game->map->player->pos[1]);
	assert(game->map->player->pos[0] == pos[0]);
	assert(game->map->player->pos[1] == pos[1]);
}

static void	test_parse_file(void)
{
	t_game	*game;

	game = parse_file("./tests/assets/maps/map1.cub");
	check_game(game, 5, 6, (int[2]){4, 3});
	free_game(game);
	game = parse_file("./tests/assets/maps/map2.cub");
	check_game(game, 5, 6, (int[2]){4, 3});
	free_game(game);
	game = parse_file("./tests/assets/maps/map3.cub");
	assert(game == NULL);
	game = parse_file("./tests/assets/maps/map4.cub");
	assert(game == NULL);
	game = parse_file("./tests/assets/maps/map5.cub");
	assert(game == NULL);
	game = parse_file("./tests/assets/maps/map6.cub");
	check_game(game, 5, 6, (int[2]){4, 3});
	free_game(game);
	game = parse_file("./tests/assets/maps/map7.cub");
	assert(game == NULL);
	game = parse_file("./tests/assets/maps/map8.cub");
	assert(game == NULL);
	game = parse_file("./tests/assets/maps/map9.cub");
	assert(game == NULL);
	game = parse_file("./tests/assets/maps/map10.cub");
	check_game(game, 5, 6, (int[2]){4, 3});
	free_game(game);
	game = parse_file("./tests/assets/maps/map11.cub");
	assert(game == NULL);
	game = parse_file("./tests/assets/maps/map12.cub");
	assert(game == NULL);
	game = parse_file("./tests/assets/maps/map13.cub");
	check_game(game, 5, 9, (int[2]){4, 3});
	free_game(game);
	game = parse_file("./tests/assets/maps/map14.cub");
	assert(game == NULL);
	game = parse_file("./tests/assets/maps/map15.cub");
	check_game(game, 14, 33, (int[2]){26, 11});
	free_game(game);
	game = parse_file("./tests/assets/maps/map16.cub");
	assert(game == NULL);
	game = parse_file("./tests/assets/maps/map17.cub");
	assert(game == NULL);
}

void	test_move_player(void)
{
	t_game		*game;
	t_map		*map;
	t_player	*player;

	game = parse_file("./tests/assets/maps/map1.cub");
	map = game->map;
	player = map->player;
	assert(player->pos[0] == 4 && player->pos[1] == 3);
	assert(map->points[3][4] == 'N');

	assert(move_player(map, UP));
	assert(player->pos[0] == 4 && player->pos[1] == 2);
	assert(map->points[3][4] == '0');
	assert(map->points[player->pos[1]][player->pos[0]] == 'N');

	assert(move_player(map, LEFT));
	assert(player->pos[0] == 3 && player->pos[1] == 2);
	assert(map->points[2][4] == '0');
	assert(map->points[player->pos[1]][player->pos[0]] == 'N');

	assert(move_player(map, DOWN));
	assert(player->pos[0] == 3 && player->pos[1] == 3);
	assert(map->points[2][3] == '0');
	assert(map->points[player->pos[1]][player->pos[0]] == 'N');

	assert(move_player(map, RIGHT));
	assert(player->pos[0] == 4 && player->pos[1] == 3);
	assert(map->points[3][3] == '0');
	assert(map->points[player->pos[1]][player->pos[0]] == 'N');

	assert(!move_player(map, RIGHT));
	assert(player->pos[0] == 4 && player->pos[1] == 3);
	assert(map->points[player->pos[1]][player->pos[0]] == 'N');
	free_game(game);
}

int	main(void)
{
	t_test_config	config;
	t_test			tests[] = {
		{&test_valid_file, "parser::test_valid_file"},
		{&test_parse_file, "parser::test_parse_file"},
		{&test_move_player, "parser::test_move_player"},
		{NULL, NULL}
	};
	init_test_config(&config);

	run_tests(tests, &config);
	return (0);
}
