/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_to_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:48:41 by apigeon           #+#    #+#             */
/*   Updated: 2022/12/29 17:48:42 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	uniformise_map(t_map *map)
{
	uint	i;
	uint	len;
	char	*tmp;

	i = 0;
	while (map->points[i])
	{
		len = ft_strlen(map->points[i]);
		if (len < map->width)
		{
			tmp = malloc(map->width + 1);
			if (!tmp)
				return (false);
			ft_memmove(tmp, map->points[i], len);
			ft_memset(tmp + len, 0, (map->width - len) + 1);
			free(map->points[i]);
			map->points[i] = tmp;
		}
		i++;
	}
	return (true);
}

static void	reverse_map(t_map *map)
{
	uint	i;

	i = 0;
	while (i < map->height)
	{
		reverse_string(map->points[i], map->width);
		i++;
	}
	set_player_pos(map);
}

t_game	*tokens_to_game(t_list *tokens)
{
	t_game	*game;

	game = init_game();
	if (!game)
		return (NULL);
	game->map = get_map(tokens);
	game->textures = get_textures(tokens);
	if (!game->map || !game->textures)
		return (free_game(game), NULL);
	if (!uniformise_map(game->map))
		return (free_game(game), NULL);
	if (can_escape_map(game->map))
		return (free_game(game), NULL);
	reverse_map(game->map);
	return (game);
}
