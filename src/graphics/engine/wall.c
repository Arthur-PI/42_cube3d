/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 22:47:33 by oaarsse           #+#    #+#             */
/*   Updated: 2023/05/09 15:14:26 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

static void	wall_height(t_game *game)
{
	t_player	*player;

	player = &game->player;
	if (player->raycasting.wall_side == VERTICAL)
		player->raycasting.perp_wall_dist = player->raycasting.side_dist.x
			- player->raycasting.delta_dist.x;
	else
		player->raycasting.perp_wall_dist = player->raycasting.side_dist.y
			- player->raycasting.delta_dist.y;
	player->raycasting.wall_height = (int)(WIN_HEIGHT / player->raycasting
			.perp_wall_dist);
	player->raycasting.draw_start = -player->raycasting.wall_height / 2
		+ WIN_HEIGHT / 2;
	if (player->raycasting.draw_start < 0)
		player->raycasting.draw_start = 0;
	player->raycasting.draw_end = player->raycasting.wall_height / 2
		+ WIN_HEIGHT / 2;
	if (player->raycasting.draw_end >= WIN_HEIGHT)
		player->raycasting.draw_end = WIN_HEIGHT;
}

static void	get_wall_txture(t_game *game)
{
	t_raycasting	*raytc;

	raytc = &game->player.raycasting;
	if (raytc->wall_side == VERTICAL)
		raytc->wall.x = game->player.position.y
			+ raytc->perp_wall_dist * -raytc->ray_dir.y;
	else
		raytc->wall.x = game->player.position.x
			+ raytc->perp_wall_dist * raytc->ray_dir.x;
	raytc->wall.x -= floor(raytc->wall.x);
	raytc->txture.x = (int)(raytc->wall.x
			* (double)TEXTURE_SIZE);
	if ((raytc->wall_side == VERTICAL && raytc->ray_dir.x < 0)
		|| (raytc->wall_side == HORIZONTAL && raytc->ray_dir.y < 0))
		raytc->txture.x = TEXTURE_SIZE
			- raytc->txture.x - 1;
}

static void	draw_wall_strip(t_game *game, int x)
{
	int				y;
	t_raycasting	*raytc;

	raytc = &game->player.raycasting;
	y = -1;
	while (++y < raytc->draw_start)
		img_pixel_put(game->img, x, y, game->textures->ceiling);
	y = game->player.raycasting.draw_start;
	while (y < game->player.raycasting.draw_end)
	{
		raytc->txture.y = (int)raytc->txture_pos & (TEXTURE_SIZE - 1);
		raytc->txture_pos += raytc->txture_step;
		img_pixel_put(game->img, x, y, texture_pixel(game));
		y++;
	}
	while (y++ < WIN_HEIGHT)
		img_pixel_put(game->img, x, y, game->textures->floor);
}

void	render_wall_line(t_game *game, int x)
{
	t_raycasting	*raytc;

	raytc = &game->player.raycasting;
	wall_height(game);
	get_wall_txture(game);
	raytc->txture_step = 1.0 * TEXTURE_SIZE
		/ raytc->wall_height;
	raytc->txture_pos = (raytc->draw_start - (WIN_HEIGHT / 2)
			+ raytc->wall_height / 2) * raytc->txture_step;
	draw_wall_strip(game, x);
}
