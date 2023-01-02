/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:48:34 by apigeon           #+#    #+#             */
/*   Updated: 2022/12/29 17:48:35 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

static t_player	*init_player(void)
{
	t_player	*player;

	player = malloc(sizeof(*player));
	if (!player)
		return (DEBUG("malloc error"), NULL);
	player->pos[0] = 0;
	player->pos[1] = 0;
	return (player);
}

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(*map));
	if (!map)
		return (DEBUG("malloc error"), NULL);
	map->height = 0;
	map->width = 0;
	map->player = init_player();
	map->points = malloc (sizeof(*(map->points)));
	if (!map->points || !map->player)
		return (DEBUG("malloc error"), free_map(map), NULL);
	map->points[0] = NULL;
	return (map);
}

t_game	*init_game(void)
{
	t_game	*game;

	game = malloc(sizeof(*game));
	if (!game)
		return (DEBUG(MSG_MALLOC_ERROR), NULL);
	game->map = NULL;
	game->textures = NULL;
	game->mlx = NULL;
	game->win = NULL;
	return (game);
}
