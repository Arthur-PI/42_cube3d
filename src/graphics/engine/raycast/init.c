/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 21:58:28 by oaarsse           #+#    #+#             */
/*   Updated: 2023/05/07 17:30:23 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	init_raycast(t_game *game, int x)
{
	game->player.raycasting.camera.x = 2 * x / (double)WIN_WIDTH - 1;
	game->player.raycasting.ray_dir = (t_vector){
		.x = game->player.direction.x + game->player.camera_plane.x
		* game->player.raycasting.camera.x,
		.y = game->player.direction.y + game->player.camera_plane.y
		* game->player.raycasting.camera.x,
	};
	game->player.raycasting.map_box = (t_int_vector){
		.x = (int)game->player.position.x,
		.y = (int)game->player.position.y,
	};
	game->player.raycasting.delta_dist = (t_vector){
		.x = fabs(1 / game->player.raycasting.ray_dir.x),
		.y = fabs(1 / game->player.raycasting.ray_dir.y),
	};
}

static void	init_rays_y(t_game *game)
{
	if (game->player.raycasting.ray_dir.y > 0)
	{
		game->player.raycasting.step.y = -1;
		game->player.raycasting.side_dist.y = (game->player.position.y
				- game->player.raycasting.map_box.y)
			* game->player.raycasting.delta_dist.y;
	}
	else
	{
		game->player.raycasting.step.y = 1;
		game->player.raycasting.side_dist.y = (game->player.raycasting.map_box.y
				+ 1.0f - game->player.position.y)
			* game->player.raycasting.delta_dist.y;
	}
}

void	init_rays(t_game *game)
{
	if (game->player.raycasting.ray_dir.x < 0)
	{
		game->player.raycasting.step.x = -1;
		game->player.raycasting.side_dist.x = (game->player.position.x
				- game->player.raycasting.map_box.x)
			* game->player.raycasting.delta_dist.x;
	}
	else
	{
		game->player.raycasting.step.x = 1;
		game->player.raycasting.side_dist.x = (game->player.raycasting.map_box.x
				+ 1.0f - game->player.position.x)
			* game->player.raycasting.delta_dist.x;
	}
	init_rays_y(game);
}
