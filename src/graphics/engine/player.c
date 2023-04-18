/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:34:20 by oaarsse           #+#    #+#             */
/*   Updated: 2023/04/18 19:56:37 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

bool	init_player(t_game *game)
{
	if (!game->map->player)
		return (false);
	game->player.position.x = game->map->player->pos[0];
	game->player.position.y = game->map->player->pos[1];
	game->player.direction.x = -1; // TODO: find a way to get the direction from the map (N, S, E, W) from the player map position
	game->player.direction.y = 0.0; // TODO: 
	game->player.camera_plane.x = 0.0;
	game->player.camera_plane.y = 0.66;
	return (true);
}
