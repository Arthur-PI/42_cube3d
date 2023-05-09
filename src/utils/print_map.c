/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 01:22:44 by oaarsse           #+#    #+#             */
/*   Updated: 2023/05/07 23:01:12 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	print_dir(t_game *game)
{
	double	x = game->player.direction.x;
	double	y = game->player.direction.y;

	if ((x == 0 && y == 1) || (x > -0.95 && x < 0.05 && y > 0.9))
		printf("→");
	else if ((x == 1 && y == 0) || (x > 0.9 && y < 0.05 && y > -0.95))
		printf("↓");
	else if ((x == 0 && y == -1) || (x > -0.95 && x < 0.05 && y < -0.9))
		printf("←");
	else if ((x == -1 && y == 0) || (x < -0.9 && y < 0.05 && y > -0.95))
		printf("↑");
	else if (x > 0 && y > 0)
		printf("↗");
	else if (x > 0 && y < 0)
		printf("↘");
	else if (x < 0 && y > 0)
		printf("↖");
	else if (x < 0 && y < 0)
		printf("↙");
}

void	print_game_live(t_game *game, t_map *map, t_player player)
{
	unsigned int	i;
	unsigned int	j;

	// system("clear");
	printf("Base position: %d, %d = %c\n", (int)game->map->player->pos[0], (int)game->map->player->pos[1], map->points[game->map->player->pos[0]][game->map->player->pos[1]]);
	printf("Player position: %u, %u\n", (unsigned int)player.position.x, (unsigned int)player.position.y);
	printf("Player movement: W:%d, S:%d\n", player.forward, player.backward);
	printf("Player movement: A:%d, D:%d\n", player.left, player.right);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if ((unsigned int)player.position.x == i && (unsigned int)player.position.y == j)
			{
				printf("\033[32m");
				print_dir(game);
				printf("\033[0m");
			}
			else if (map->points[i][j] == '1')
				printf("\033[31m%c\033[32m", map->points[i][j]);
			else if (map->points[i][j] == '0')
				printf("\033[34m%c\033[0m", map->points[i][j]);
			else if (map->points[i][j] == ' ')
				printf("%c\033[0m", map->points[i][j]);
			else
			{
				printf("\033[1m\033[35m%c\033[0m", map->points[i][j]);
			}
			j++;
		}
		printf("\n");
		i++;
	}
}
