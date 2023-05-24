/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:53:16 by apigeon           #+#    #+#             */
/*   Updated: 2023/05/06 01:18:03 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

static int	stop_loop(void *mlx)
{
	mlx_loop_end(mlx);
	return (0);
}

static int	key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->player.forward = false;
	if (keycode == KEY_S)
		game->player.backward = false;
	if (keycode == KEY_A)
		game->player.left = false;
	if (keycode == KEY_D)
		game->player.right = false;
	if (keycode == KEY_ARROW_LEFT)
		game->player.rotate_left = false;
	if (keycode == KEY_ARROW_RIGHT)
		game->player.rotate_right = false;
	return (0);
}

static int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		stop_loop(game->mlx);
	if (keycode == KEY_W)
		game->player.forward = true;
	if (keycode == KEY_S)
		game->player.backward = true;
	if (keycode == KEY_A)
		game->player.left = true;
	if (keycode == KEY_D)
		game->player.right = true;
	if (keycode == KEY_ARROW_LEFT)
		game->player.rotate_left = true;
	if (keycode == KEY_ARROW_RIGHT)
		game->player.rotate_right = true;
	return (0);
}

void	setup_hooks(t_game *game)
{
	mlx_hook(game->win, ON_DESTROY, MASK_NO_EVENT, &stop_loop, game->mlx);
	mlx_hook(game->win, ON_KEYDOWN, MASK_KEY_PRESS, &key_press, game);
	mlx_hook(game->win, ON_KEYUP, MASK_KEY_RELEASE, &key_release, game);
	mlx_loop_hook(game->mlx, game_loop, game);
}
