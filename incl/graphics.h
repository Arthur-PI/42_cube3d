/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 23:09:47 by apigeon           #+#    #+#             */
/*   Updated: 2023/01/03 23:09:50 by apigeon          ###   ########.fr       */
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

#endif
