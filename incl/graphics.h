/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 23:09:47 by apigeon           #+#    #+#             */
/*   Updated: 2023/04/18 17:42:05 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "stdbool.h"
# include "mlx.h"
# include "struct.h"
# include "constant.h"

int		load_textures(void *mlx, t_textures *textures);
int		init_graphics(t_game *game);
void	setup_hooks(t_game *game);
void	img_pixel_put(t_img *img, int x, int y, int color);
void	free_img(void *mlx, t_img *img);
void	render_img(t_game *game, t_img *img);
t_img	*new_image(void *mlx);
void	draw_vertical_line(t_img *img, int x, t_int_vector line, int color);

#endif
