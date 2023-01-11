/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:53:16 by apigeon           #+#    #+#             */
/*   Updated: 2022/07/20 18:56:15 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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
	mlx_hook(game->win, ON_DESTROY, MASK_NO_EVENT,
		(void (*)(void)) & stop_loop, game->mlx);
	mlx_hook(game->win, ON_KEYDOWN, MASK_KEY_PRESS,
		(void (*)(void)) & key_hook, game);
}
