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

# include "mlx.h"
# include "struct.h"
# include "constant.h"

int		load_textures(void *mlx, t_textures *textures);
int		init_graphics(t_game *game);
void	setup_hooks(t_game *game);

#endif
