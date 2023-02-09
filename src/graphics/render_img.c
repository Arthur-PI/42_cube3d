/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:10:26 by apigeon           #+#    #+#             */
/*   Updated: 2022/12/11 20:43:11 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void	render_img(t_game *game, t_img *img)
{
	t_img	*old_img;

	old_img = game->img;
	game->img = img;
	mlx_put_image_to_window(game->mlx, game->win, img->img, 0, 0);
	if (old_img != img)
		free_img(game->mlx, old_img);
}
