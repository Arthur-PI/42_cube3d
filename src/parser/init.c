/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:48:34 by apigeon           #+#    #+#             */
/*   Updated: 2023/04/18 13:56:05 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

static t_player_pos	*init_player(void)
{
	t_player_pos	*player;

	player = malloc(sizeof(*player));
	if (!player)
		return (NULL);
	player->pos[0] = 0;
	player->pos[1] = 0;
	return (player);
}

t_textures	*init_textures(void)
{
	t_textures	*textures;

	textures = malloc(sizeof(*textures));
	if (!textures)
		return (NULL);
	textures->ceiling = 0;
	textures->floor = 0;
	textures->wall_north = NULL;
	textures->wall_south = NULL;
	textures->wall_west = NULL;
	textures->wall_east = NULL;
	return (textures);
}

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(*map));
	if (!map)
		return (NULL);
	map->height = 0;
	map->width = 0;
	map->player = init_player();
	if (!map->player)
		return (free_map(map), NULL);
	map->points = malloc (sizeof(*(map->points)));
	if (!map->points)
		return (free_map(map), NULL);
	map->points[0] = NULL;
	return (map);
}

t_game	*init_game(void)
{
	t_game	*game;

	game = malloc(sizeof(*game));
	if (!game)
		return (NULL);
	game->map = NULL;
	game->textures = NULL;
	game->mlx = NULL;
	game->win = NULL;
	game->img = NULL;
	return (game);
}
