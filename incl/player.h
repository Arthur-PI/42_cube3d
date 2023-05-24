/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:58:32 by oaarsse           #+#    #+#             */
/*   Updated: 2023/05/06 00:55:19 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include <stdbool.h>
# include "struct.h"

// vector struct
// double x: x coordinate
// double y: y coordinate
typedef struct s_vector {
	double	x;
	double	y;
}	t_vector;

typedef struct s_int_vector {
	int	x;
	int	y;
}	t_int_vector;

/*
* raycasting struct
* . map_box: t_int_vector (x and y coordinates) (index in the map (int))
* . camera: double (camera x coordinate)
* . ray_dir: t_vector (x and y coordinates) (ray direction)
* . side_dist: t_vector (x and y coordinates) (distance to the next side)
* . delta_dist: t_vector (x and y coordinates) (length of the ray)
* . step: t_vector (x and y coordinates) (step to take)
* . wall_side: int (1: NS, 0: EW)
* . perp_wall_dist: double (perpendicular wall distance) used to avoid fish eye
*/
typedef struct s_raycasting {
	t_int_vector	map_box;
	t_vector		camera;
	t_vector		ray_dir;
	t_vector		side_dist;
	t_vector		delta_dist;
	t_vector		step;
	int				wall_side;
	double			perp_wall_dist;
	int				wall_height;
	int				draw_start;
	int				draw_end;

	t_vector		wall;
	t_int_vector	txture;
	double			txture_step;
	double			txture_pos;
}	t_raycasting;

/*
player's struct
* . position: t_vector (x and y coordinates)
* . direction: t_vector (x and y coordinates)
* . camera_plane: t_vector (x and y coordinates)
* . raycasting: t_raycasting (raycasting struct)
*/
typedef struct s_player
{
	t_vector		position;
	t_vector		direction;
	t_vector		camera_plane;
	t_raycasting	raycasting;

	bool			forward;
	bool			backward;
	bool			left;
	bool			right;

	bool			rotate_left;
	bool			rotate_right;
}	t_player;

#endif