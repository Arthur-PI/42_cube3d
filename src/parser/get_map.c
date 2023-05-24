/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:48:51 by apigeon           #+#    #+#             */
/*   Updated: 2023/05/06 02:04:46 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static uint	tablen(char **data)
{
	uint	i;

	i = 0;
	while (data[i])
		i++;
	return (i);
}

static char	*add_map_row(t_map *map, t_token *token)
{
	uint	i;
	uint	len;
	char	**new_points;
	char	*new_row;

	len = tablen(map->points);
	new_points = malloc((++len + 1) * sizeof(*new_points));
	if (!new_points)
		return (DEBUG("malloc error"), NULL);
	new_row = ft_strdup(token->value);
	if (!new_row)
		return (DEBUG("malloc error"), free(new_points), NULL);
	trim_end(new_row);
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
	return (new_row);
}

static bool	isplayer(char c)
{
	if (c == 'N' || c == 'S')
		return (true);
	if (c == 'W' || c == 'E')
		return (true);
	return (false);
}

static bool	set_player_pos(t_map *map)
{
	uint	i;
	uint	j;
	bool	found;

	i = -1;
	found = false;
	while (map->points[++i])
	{
		j = 0;
		while (map->points[i][j])
		{
			if (isplayer(map->points[i][j]))
			{
				if (found)
					return (DEBUG("Too many players on the map !"), false);
				map->player->pos[0] = i;
				map->player->pos[1] = j;
				found = true;
			}
			j++;
		}
	}
	if (!found)
		DEBUG("No player found on the map !");
	return (found);
}

t_map	*get_map(t_list *tokens)
{
	char	*row;
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
			row = add_map_row(map, token);
			if (!row)
				return (free_map(map), NULL);
			map->width = MAX(map->width, ft_strlen(row));
			map->height++;
		}
		tokens = tokens->next;
	}
	if (!set_player_pos(map))
		return (free_map(map), NULL);
	return (map);
}
