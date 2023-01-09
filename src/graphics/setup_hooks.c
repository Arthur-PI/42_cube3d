#include "graphics.h"

static int	stop_loop(void *mlx)
{
	mlx_loop_end(mlx);
	return (0);
}

static int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		stop_loop(game->mlx);
	return (0);
}

void	setup_hooks(t_game *game)
{
	mlx_hook(game->win, ON_DESTROY, MASK_NO_EVENT, &stop_loop, game->mlx);
	mlx_hook(game->win, ON_KEYDOWN, MASK_KEY_PRESS, &key_hook, game);
}
