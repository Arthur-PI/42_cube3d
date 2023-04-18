/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:48:01 by apigeon           #+#    #+#             */
/*   Updated: 2023/04/18 13:55:35 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

static void	free_player(t_player_pos *player)
{
	if (player)
	{
		free(player);
	}
}

void	free_map(t_map *map)
{
	if (map)
	{
		free_points(map->points);
		free_player(map->player);
		free(map);
	}
}
