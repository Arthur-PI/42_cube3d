/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:10:26 by apigeon           #+#    #+#             */
/*   Updated: 2022/12/11 20:43:11 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

bool	_move_player(t_map *map, int offx, int offy)
{
	int	posx;
	int	posy;

	posx = map->player->pos[0] + offx;
	posy = map->player->pos[1] + offy;
	if (map->points[posy][posx] == '1')
		return (false);
	map->points[posy][posx] = map->points[posy - offy][posx - offx];
	map->points[posy - offy][posx - offx] = '0';
	map->player->pos[0] = posx;
	map->player->pos[1] = posy;
	return (true);
}

bool	move_player(t_map *map, t_direction dir)
{
	bool	ret;

	ret = false;
	if (dir == UP)
		ret = _move_player(map, 0, -1);
	else if (dir == DOWN)
		ret = _move_player(map, 0, 1);
	else if (dir == LEFT)
		ret = _move_player(map, -1, 0);
	else if (dir == RIGHT)
		ret = _move_player(map, 1, 0);
	return (ret);
}
