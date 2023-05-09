/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:57:12 by oaarsse           #+#    #+#             */
/*   Updated: 2023/05/07 17:29:11 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

static void	render_floor_ceiling(t_game	*game)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (y < round(WIN_HEIGHT / 2))
				img_pixel_put(game->img, x, y, game->textures->ceiling);
			else
				img_pixel_put(game->img, x, y, game->textures->floor);
			x++;
		}
		y++;
	}
}

// Display to the window what the player need to see
// starts by rendering the ceilling and floor colors
// then overwrites the ceilling + floor pixels to render player's view
void	render(t_game	*game)
{
	int	x;

	render_floor_ceiling(game);
	x = 0;
	while (x < WIN_WIDTH)
	{
		init_raycast(game, x);
		init_rays(game);
		dda(game);
		render_wall_line(game, x);
		x++;
	}
	render_img(game, game->img);
}
