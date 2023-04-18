/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:30:04 by oaarsse           #+#    #+#             */
/*   Updated: 2023/04/18 19:56:54 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

// only here cuz of the 25 lines limit of the code norm
static void	init_rays(t_game *game)
{
	game->player.raycasting.step.x = 1;
	game->player.raycasting.side_dist.x = (
			game->player.raycasting.map_box.x
			+ 1.0 - game->player.position.x)
		* game->player.raycasting.delta_dist.x;
	if (game->player.raycasting.ray_dir.x < 0)
	{
		game->player.raycasting.step.x = -1;
		game->player.raycasting.side_dist.x = (game->player.position.x
				- game->player.raycasting.map_box.x)
			* game->player.raycasting.delta_dist.x;
	}
	game->player.raycasting.step.y = 1;
	game->player.raycasting.side_dist.y = (
			game->player.raycasting.map_box.y
			+ 1.0 - game->player.position.y)
		* game->player.raycasting.delta_dist.y;
	if (game->player.raycasting.ray_dir.y < 0)
	{
		game->player.raycasting.step.y = -1;
		game->player.raycasting.side_dist.y = (game->player.position.y
				- game->player.raycasting.map_box.y)
			* game->player.raycasting.delta_dist.y;
	}
}

// create all raycasting lines and other stuffs for calculating the distances
static void	init_dda(t_game *game, int x)
{
	game->player.raycasting.camera = (t_vector){.x = 2 * x / WIN_WIDTH - 1};
	game->player.raycasting.ray_dir = (t_vector){
		.x = game->player.direction.x + game->player.camera_plane.x
		* game->player.raycasting.camera.x,
		.y = game->player.direction.y + game->player.camera_plane.y
		* game->player.raycasting.camera.x};
	game->player.raycasting.map_box = (t_int_vector){
		.x = floor(game->player.position.x),
		.y = floor(game->player.position.y)
	};
	game->player.raycasting.delta_dist = (t_vector){
		.x = fabs(1 / game->player.raycasting.ray_dir.x),
		.y = fabs(1 / game->player.raycasting.ray_dir.y)
	};
	if (game->player.raycasting.ray_dir.x == 0)
		game->player.raycasting.delta_dist = (t_vector){
			.x = DBL_MAX,
		};
	if (game->player.raycasting.ray_dir.y == 0)
		game->player.raycasting.delta_dist = (t_vector){
			.y = DBL_MAX,
		};
	init_rays(game);
}

// jumps to next map square, either in x-direction, OR in y-direction
static void	dda_calc(t_game *game)
{
	if (game->player.raycasting.side_dist.x
		< game->player.raycasting.side_dist.y)
	{
		game->player.raycasting.side_dist.x
			+= game->player.raycasting.delta_dist.x;
		game->player.raycasting.map_box.x
			+= game->player.raycasting.step.x;
		game->player.raycasting.wall_side = 0;
	}
	else
	{
		game->player.raycasting.side_dist.y
			+= game->player.raycasting.delta_dist.y;
		game->player.raycasting.map_box.y
			+= game->player.raycasting.step.y;
		game->player.raycasting.wall_side = 1;
	}
}

// Digital Differential Analysis
// algorithm used on square grids to find which squares a raycasting line hits
// TODO: here add textures data stuff
int	dda(t_game *game, int x)
{
	bool	has_hit_wall;

	init_dda(game, x);
	has_hit_wall = false;
	while (!has_hit_wall)
	{
		dda_calc(game);
		if (game->player.raycasting.map_box.x >= 0
			&& game->player.raycasting.map_box.x < (int)game->map->width - 1
			& game->player.raycasting.map_box.y >= 0
			&& game->player.raycasting.map_box.y < (int)game->map->height - 1)
		{
			if (game->map->points[game->player.raycasting.map_box.x]
				[game->player.raycasting.map_box.y] > 0)
				has_hit_wall = true;
		}
	}
	return (0);
}
