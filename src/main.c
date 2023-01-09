/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:10:26 by apigeon           #+#    #+#             */
/*   Updated: 2022/12/11 20:43:11 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	usage(const char *prog_name)
{
	printf("Usage: %s <map.cub>\n", prog_name);
}

static void	print_game(t_game *game)
{
	int	i;

	printf("Game:\n");
	printf(" - textures:\n");
	printf("   - north wall: %s\n", game->textures->wall_north->file);
	printf("   - south wall: %s\n", game->textures->wall_south->file);
	printf("   - west wall: %s\n", game->textures->wall_west->file);
	printf("   - east wall: %s\n", game->textures->wall_east->file);
	printf("   - ceiling: %x\n", game->textures->ceiling);
	printf("   - floor: %x\n", game->textures->floor);
	printf(" - map:\n");
	printf("   - width: %d\n", game->map->width);
	printf("   - height: %d\n", game->map->height);
	printf("   - player: (%d,%d)\n", game->map->player->pos[0],
		game->map->player->pos[1]);
	i = 0;
	while (game->map->points[i])
		printf("   > %s\n", game->map->points[i++]);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		return (usage(av[0]), 1);
	game = parse_file(av[1]);
	if (game == NULL)
		exit(2);
	print_game(game);
	if (init_graphics(game) == -1)
		return (free_game(game), 3);
	if (load_textures(game->mlx, game->textures) == -1)
		return (free_game(game), 4);
	setup_hooks(game);
	mlx_loop(game->mlx);
	free_game(game);
	return (0);
}
