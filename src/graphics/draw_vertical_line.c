/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:39:43 by oaarsse           #+#    #+#             */
/*   Updated: 2023/04/18 17:41:51 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void	draw_vertical_line(t_img *img, int x, t_int_vector line, int color)
{
	int		y;

	y = line.x;
	while (y < line.y)
	{
		img_pixel_put(img, x, y, color);
		y++;
	}
}
