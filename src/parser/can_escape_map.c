/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_escape_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:48:58 by apigeon           #+#    #+#             */
/*   Updated: 2022/12/29 17:48:59 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	is_neighbour_void(char **points, uint i, uint j)
{
	if (i == 0 || j == 0 || points[i + 1] == 0 || points[i][j + 1] == 0)
		return (true);
	if (points[i - 1][j] == ' ' || points[i + 1][j] == ' ')
		return (true);
	if (points[i - 1][j] == 0 || points[i + 1][j] == 0)
		return (true);
	if (points[i][j - 1] == ' ' || points[i][j + 1] == ' ')
		return (true);
	return (false);
}

bool	can_escape_map(t_map *map)
{
	uint	i;
	uint	j;

	i = 0;
	while (map->points[i])
	{
		j = 0;
		while (map->points[i][j])
		{
			if (map->points[i][j] != '1' && map->points[i][j] != ' ')
			{
				if (is_neighbour_void(map->points, i, j))
					return (DEBUG("The map is not protected by walls"), true);
			}
			j++;
		}
		i++;
	}
	return (false);
}
