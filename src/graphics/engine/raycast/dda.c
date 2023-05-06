/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 22:28:44 by oaarsse           #+#    #+#             */
/*   Updated: 2023/05/06 03:13:07 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	dda(t_game *game)
{
	bool		hit;
	t_player	*player;

	hit = false;
	player = &game->player;
	while (!hit)
	{
		if (player->raycasting.side_dist.x < player->raycasting.side_dist.y)
		{
			player->raycasting.side_dist.x += player->raycasting.delta_dist.x;
			player->raycasting.map_box.x += player->raycasting.step.x;
			player->raycasting.wall_side = VERTICAL;
		}
		else
		{
			player->raycasting.side_dist.y += player->raycasting.delta_dist.y;
			player->raycasting.map_box.y += player->raycasting.step.y;
			player->raycasting.wall_side = HORIZONTAL;
		}
		if (game->map->points[player->raycasting.map_box.x]
			[player->raycasting.map_box.y] == WALL)
			hit = true;
	}
}
