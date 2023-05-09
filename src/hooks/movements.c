/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 00:37:27 by oaarsse           #+#    #+#             */
/*   Updated: 2023/05/09 14:59:11 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

static void	forward(t_game *game)
{
	if (game->map->points[(int)(game->player.position.x
			+ game->player.direction.x * HITBOX)]
			[(int)game->player.position.y] != WALL)
		game->player.position.x += game->player.direction.x * SPEED;
	if (game->map->points [(int)game->player.position.x]
		[(int)(game->player.position.y
			- game->player.direction.y * HITBOX)] != WALL)
		game->player.position.y -= game->player.direction.y * SPEED;
}

static void	backward(t_game *game)
{
	if (game->map->points [(int)(game->player.position.x
			- game->player.direction.x * HITBOX)]
			[(int)game->player.position.y] != WALL)
		game->player.position.x -= game->player.direction.x * SPEED;
	if (game->map->points[(int)game->player.position.x]
		[(int)(game->player.position.y
			+ game->player.direction.y * HITBOX)] != WALL)
		game->player.position.y += game->player.direction.y * SPEED;
}

static void	left(t_game *game)
{
	if (game->map->points[(int)(game->player.position.x
			- game->player.direction.y * HITBOX)]
			[(int)game->player.position.y] != WALL)
		game->player.position.x -= game->player.direction.y * SPEED;
	if (game->map->points[(int)game->player.position.x]
		[(int)(game->player.position.y
			- game->player.direction.x * HITBOX)] != WALL)
		game->player.position.y -= game->player.direction.x * SPEED;
}

static void	right(t_game *game)
{
	if (game->map->points[(int)(game->player.position.x
			+ game->player.direction.y * HITBOX)]
			[(int)game->player.position.y] != WALL)
		game->player.position.x += game->player.direction.y * SPEED;
	if (game->map->points[(int)game->player.position.x]
		[(int)(game->player.position.y
			+ game->player.direction.x * HITBOX)] != WALL)
		game->player.position.y += game->player.direction.x * SPEED;
}

void	exec_player_movements(t_game *game)
{
	if (game->player.forward)
		forward(game);
	if (game->player.backward)
		backward(game);
	if (game->player.left)
		left(game);
	if (game->player.right)
		right(game);
}
