/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:48:51 by apigeon           #+#    #+#             */
/*   Updated: 2022/12/29 17:48:52 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	add_map_row(t_map *map, t_token *token)
{
	uint	i;
	uint	len;
	char	**new_points;
	char	*new_row;

	len = 0;
	while (map->points[len])
		len++;
	new_points = malloc((++len + 1) * sizeof(*new_points));
	if (!new_points)
		return (DEBUG("malloc error"), false);
	new_row = ft_strdup(token->value);
	if (!new_row)
		return (DEBUG("malloc error"), free(new_points), false);
	i = 0;
	while (i < (len - 1))
	{
		new_points[i] = map->points[i];
		i++;
	}
	new_points[i++] = new_row;
	new_points[i] = NULL;
	free(map->points);
	map->points = new_points;
	return (true);
}

static bool	isplayer(char c)
{
	if (c == 'N' || c == 'S')
		return (true);
	if (c == 'W' || c == 'E')
		return (true);
	return (false);
}

static void	set_player_pos(t_player *player, char *row, uint y)
{
	uint		i;
	static bool	pos_found = false;

	if (!pos_found)
	{
		i = 0;
		while (row[i])
		{
			if (isplayer(row[i]))
			{
				player->pos[0] = i;
				player->pos[1] = y;
				pos_found = true;
				return ;
			}
			i++;
		}
	}
}

t_map	*get_map(t_list *tokens)
{
	t_map	*map;
	t_token	*token;

	map = init_map();
	if (!map)
		return (NULL);
	while (tokens)
	{
		token = tokens->content;
		if (token->type == TOKEN_MAP)
		{
			if (!add_map_row(map, token))
				return (free_map(map), NULL);
			set_player_pos(map->player, token->value, map->height);
			map->width = MAX(map->width, ft_strlen(token->value));
			map->height++;
		}
		tokens = tokens->next;
	}
	return (map);
}
