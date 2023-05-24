/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:47:40 by apigeon           #+#    #+#             */
/*   Updated: 2022/12/29 17:47:42 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

static void	free_texture(void *mlx, t_texture *texture)
{
	if (texture)
	{
		if (texture->img)
			mlx_destroy_image(mlx, texture->img);
		free(texture->file);
		if (texture->address)
			free(texture->address)
		free(texture);
	}
}

static void	free_textures(void *mlx, t_textures *textures)
{
	if (textures)
	{
		free_texture(mlx, textures->wall_north);
		free_texture(mlx, textures->wall_south);
		free_texture(mlx, textures->wall_west);
		free_texture(mlx, textures->wall_east);
		free(textures);
	}
}

void	free_game(t_game *game)
{
	if (game)
	{
		free_map(game->map);
		free_textures(game->mlx, game->textures);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		if (game->mlx)
		{
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
		free(game);
	}
}
