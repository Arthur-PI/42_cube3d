/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:57:12 by oaarsse           #+#    #+#             */
/*   Updated: 2023/05/09 14:39:08 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

// Display to the window what the player need to see
// starts by rendering the ceilling and floor colors
// then overwrites the ceilling + floor pixels to render player's view
void	render(t_game	*game)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		init_raycast(game, x);
		init_rays(game);
		dda(game);
		render_wall_line(game, x);
		x++;
	}
	render_img(game, game->img);
}
