/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 23:10:10 by apigeon           #+#    #+#             */
/*   Updated: 2023/05/06 00:18:51 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

static int	load_texture(void *mlx, t_texture *t)
{
	t->img = mlx_xpm_file_to_image(mlx, t->file, &t->width, &t->height);
	if (!t->img)
		return (DEBUG(MSG_ERROR_XPM_LOAD), -1);
	t->address = mlx_get_data_addr(t->img, &t->bits_per_pixel,
			&t->line_length, &t->endian);
	return (1);
}

int	load_textures(void *mlx, t_textures *textures)
{
	if (load_texture(mlx, textures->wall_north) == -1)
		return (DEBUG("can't load north wall texture"), -1);
	if (load_texture(mlx, textures->wall_south) == -1)
		return (DEBUG("can't load south wall texture"), -1);
	if (load_texture(mlx, textures->wall_west) == -1)
		return (DEBUG("can't load west wall texture"), -1);
	if (load_texture(mlx, textures->wall_east) == -1)
		return (DEBUG("can't load east wall texture"), -1);
	return (1);
}
