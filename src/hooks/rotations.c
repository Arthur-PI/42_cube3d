/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 00:39:49 by oaarsse           #+#    #+#             */
/*   Updated: 2023/05/06 02:46:19 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

static void	right(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	print_game_live(game, game->map, game->player);
	old_dir_x = game->player.direction.x;
	game->player.direction.x = game->player.direction.x * cos(-ROT_SPEED)
		- game->player.direction.y * sin(-ROT_SPEED);
	game->player.direction.y = old_dir_x * sin(-ROT_SPEED)
		+ game->player.direction.y * cos(-ROT_SPEED);
	old_plane_x = game->player.camera_plane.x;
	game->player.camera_plane.x = game->player.camera_plane.x * cos(-ROT_SPEED)
		- game->player.camera_plane.y * sin(-ROT_SPEED);
	game->player.camera_plane.y = old_plane_x * sin(-ROT_SPEED)
		+ game->player.camera_plane.y * cos(-ROT_SPEED);
}

static void	left(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	print_game_live(game, game->map, game->player);
	old_dir_x = game->player.direction.x;
	game->player.direction.x = game->player.direction.x * cos(ROT_SPEED)
		- game->player.direction.y * sin(ROT_SPEED);
	game->player.direction.y = old_dir_x * sin(ROT_SPEED)
		+ game->player.direction.y * cos(ROT_SPEED);
	old_plane_x = game->player.camera_plane.x;
	game->player.camera_plane.x = game->player.camera_plane.x * cos(ROT_SPEED)
		- game->player.camera_plane.y * sin(ROT_SPEED);
	game->player.camera_plane.y = old_plane_x * sin(ROT_SPEED)
		+ game->player.camera_plane.y * cos(ROT_SPEED);
}

void	exec_player_rotations(t_game *game)
{
	if (game->player.rotate_right)
		right(game);
	if (game->player.rotate_left)
		left(game);
	return ;
}
