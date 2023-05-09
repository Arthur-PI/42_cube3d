/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 23:22:26 by oaarsse           #+#    #+#             */
/*   Updated: 2023/05/09 16:51:41 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

// static unsigned int	get_pixel(t_texture *txture, int x, int y)
// {
// 	return (*(unsigned int *)(txture->address)
// 		+ (y * txture->line_length)
// 		+ (x * txture->bits_per_pixel / 8));
// }

static unsigned int	get_pixel(t_texture *tex, int x, int y)
{
	unsigned int	colour;
	char			*dst;

	dst = tex->address + (y * tex->line_length
			+ (x * (tex->bits_per_pixel / 8)));
	colour = *(unsigned int *)dst;
	return (colour);
}

unsigned int	texture_pixel(t_game *game)
{
	t_raycasting	raytc;

	raytc = game->player.raycasting;
	if (raytc.wall_side == VERTICAL)
	{
		if (game->player.position.x > raytc.map_box.x)
			return (get_pixel(game->textures->wall_west,
					raytc.txture.x, raytc.txture.y));
		return (get_pixel(game->textures->wall_east,
				raytc.txture.x, raytc.txture.y));
	}
	else
	{
		if (game->player.position.y > raytc.map_box.y)
			return (get_pixel(game->textures->wall_north,
					raytc.txture.x, raytc.txture.y));
		return (get_pixel(game->textures->wall_south,
				raytc.txture.x, raytc.txture.y));
	}
}
