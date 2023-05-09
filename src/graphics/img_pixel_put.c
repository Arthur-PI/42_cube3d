/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_pixel_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:10:26 by apigeon           #+#    #+#             */
/*   Updated: 2023/05/07 18:12:02 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

static bool	pixel_in_window(int x, int y)
{
	if (x < 0 || y < 0)
		return (false);
	if (x >= WIN_WIDTH || y >= WIN_HEIGHT)
		return (false);
	return (true);
}

void	img_pixel_put(t_img *img, int x, int y, unsigned int color)
{
	int	offset;

	if (pixel_in_window(x, y))
	{
		offset = (y * img->line_length + (x * img->bits_per_pixel / 8));
		img->addr[offset++] = color;
		img->addr[offset++] = color >> 8;
		img->addr[offset] = color >> 16;
	}
}
