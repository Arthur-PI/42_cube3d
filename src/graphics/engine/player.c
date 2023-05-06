/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:34:20 by oaarsse           #+#    #+#             */
/*   Updated: 2023/05/06 03:19:23 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

t_vector	orientation(char pos)
{
	t_vector	orientation;

	if (pos == 'N' || pos == 'n')
		orientation = (t_vector){0.0f, 1.0f};
	else if (pos == 'E' || pos == 'e')
		orientation = (t_vector){1.0f, 0.0f};
	else if (pos == 'S' || pos == 's')
		orientation = (t_vector){0.0f, -1.0f};
	else if (pos == 'W' || pos == 'w')
		orientation = (t_vector){-1.0f, 0.0f};
	else
	{
		printf("Error: invalid orientation\n");
		orientation = (t_vector){0.0f, 1.0f};
	}
	return (orientation);
}

t_vector	plane(char pos)
{
	t_vector	dir_plane;

	if (pos == 'N' || pos == 'n')
		dir_plane = (t_vector){0.66, 0};
	else if (pos == 'E' || pos == 'e')
		dir_plane = (t_vector){0, -0.66};
	else if (pos == 'S' || pos == 's')
		dir_plane = (t_vector){-0.66, 0};
	else if (pos == 'W' || pos == 'w')
		dir_plane = (t_vector){0, 0.66};
	else
	{
		printf("Error: invalid plane\n");
		dir_plane = (t_vector){0.66, 0};
	}
	return (dir_plane);
}

bool	init_player(t_game *game)
{
	int	x;
	int	y;

	if (!game->map->player || !game->map->points)
		return (false);
	x = game->map->player->pos[0];
	y = game->map->player->pos[1];
	game->player.position.x = x + 0.5;
	game->player.position.y = y + 0.5;
	game->player.direction = orientation(game->map->points[x][y]);
	game->player.camera_plane = plane(game->map->points[x][y]);
	game->player.forward = false;
	game->player.backward = false;
	game->player.left = false;
	game->player.right = false;
	game->player.rotate_left = false;
	game->player.rotate_right = false;
	game->map->points[x][y] = '0';
	return (true);
}
