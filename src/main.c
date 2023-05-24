/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:10:26 by apigeon           #+#    #+#             */
/*   Updated: 2023/05/05 21:56:07 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	usage(const char *prog_name)
{
	printf("Usage: %s <map.cub>\n", prog_name);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		return (usage(av[0]), 1);
	game = parse_file(av[1]);
	if (game == NULL)
		exit(2);
	if (init_graphics(game) == -1)
		return (printf("Error\n"), free_game(game), 3);
	if (load_textures(game->mlx, game->textures) == -1)
		return (printf("Error\n"), free_game(game), 4);
	init_player(game);
	render(game);
	setup_hooks(game);
	mlx_loop(game->mlx);
	free_game(game);
	return (0);
}
