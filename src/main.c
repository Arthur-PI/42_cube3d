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

int	main(int ac, char **av)
{
	void	*map;

	if (ac != 2)
		return (usage(av[0]), 1);
	map = parse_file(av[1]);
	(void)map;
	return (0);
}
