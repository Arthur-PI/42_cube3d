#include "graphics.h"

int	init_graphics(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (DEBUG("can't instanciate mlx"), -1);
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (!game->win)
		return (DEBUG("can't instanciate mlx window"), free(game->mlx), -1);
	return (1);
}
