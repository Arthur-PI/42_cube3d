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

#include "struct.h"

// TODO free all xpm loaded textures with mlx_destroy_image
static void	free_texture(t_texture *texture)
{
	if (texture)
	{
		free(texture->file);
		free(texture);
	}
}

static void	free_textures(t_textures *textures)
{
	if (textures)
	{
		free_texture(textures->wall_north);
		free_texture(textures->wall_south);
		free_texture(textures->wall_west);
		free_texture(textures->wall_east);
		free(textures);
	}
}

void	free_game(t_game *game)
{
	if (game)
	{
		free_map(game->map);
		free_textures(game->textures);
		free(game);
	}
}
