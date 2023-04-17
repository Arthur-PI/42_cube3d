/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:57:12 by oaarsse           #+#    #+#             */
/*   Updated: 2023/04/17 22:20:52 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

// Generate the int value of the combined:
// - t: transparency (0: opaque)
// - r: red (0 -> 255)
// - g: green (0 -> 255)
// - b: blue (0 -> 255)
// static int	create_trgb(int t, int r, int g, int b)
// {
// 	return (t << 24 | r << 16 | g << 8 | b);
// }

// Display to the window what the player sees
void	render(t_game	*game)
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
	render_img(game, game->img);
}
