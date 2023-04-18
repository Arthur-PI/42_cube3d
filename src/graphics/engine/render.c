/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:57:12 by oaarsse           #+#    #+#             */
/*   Updated: 2023/04/18 19:57:59 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

static void	render_wall_vertical_line(t_game *game, int x)
{
	int		wall_height;
	int		wall_start;
	int		wall_end;
	int color = 0x00FF00;

	printf("side: %d\n", game->player.raycasting.wall_side);
	printf("perp_wall_dist: %f\n", game->player.raycasting.perp_wall_dist);
	wall_height = floor(WIN_HEIGHT / game->player.raycasting.perp_wall_dist);
	wall_start = floor(-wall_height / 2 + WIN_HEIGHT / 2);
	if (wall_start < 0)
		wall_start = 0;
	wall_end = floor(wall_height / 2 + WIN_HEIGHT / 2);
	if (wall_end >= WIN_HEIGHT)
		wall_end = WIN_HEIGHT;
	// TODO: colors here
	if (game->player.raycasting.wall_side == 0)
		color /= 2;
	printf("[%d, %d]: %d\n", wall_start, wall_end, wall_height);
	draw_vertical_line(game->img, x, (t_int_vector){wall_start, wall_end},
		color);
}

// calculate the distance between the player and the wall
// used to avoid fisheye effect when rendering the walls
static void	calc_perp_wall_dist(t_game *game)
{
	if (game->player.raycasting.wall_side == 0)
		game->player.raycasting.perp_wall_dist
			= (game->player.raycasting.side_dist.x
				- game->player.raycasting.delta_dist.x);
	else
		game->player.raycasting.perp_wall_dist
			= (game->player.raycasting.side_dist.y
				- game->player.raycasting.delta_dist.y);
}

// Render the player's view to the game image
static void	render_players_view(t_game	*game)
{
	int			x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		dda(game, x);
		calc_perp_wall_dist(game);
		render_wall_vertical_line(game, x);
		x++;
	}
	return ;
}

// Display to the window what the player need to see
// starts by rendering the ceilling and floor colors
// then overwrites the ceilling + floor pixels to render player's view
void	render(t_game	*game)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (y < round(WIN_HEIGHT / 2))
				img_pixel_put(game->img, x, y, game->textures->ceiling);
			else
				img_pixel_put(game->img, x, y, game->textures->floor);
			x++;
		}
		y++;
	}
	init_player(game);
	render_players_view(game);
	draw_vertical_line(game->img, 10, (t_int_vector){0, WIN_HEIGHT}, 0xFF0000);
	render_img(game, game->img);
}
