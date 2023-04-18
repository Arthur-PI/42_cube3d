/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:47:13 by apigeon           #+#    #+#             */
/*   Updated: 2023/04/18 15:33:29 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdlib.h>
# include <sys/types.h>
# include "error.h"
# include "player.h"

typedef enum e_token_type
{
	TOKEN_UNDIFINED,
	TOKEN_MAP,
	TOKEN_NORTH,
	TOKEN_SOUTH,
	TOKEN_WEST,
	TOKEN_EAST,
	TOKEN_CEILING,
	TOKEN_FLOOR
}			t_token_type;

typedef enum e_direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
}			t_direction;

typedef struct s_token
{
	t_token_type	type;
	char			*value;
}				t_token;

// pos[0] -> x, pos[1] -> y
typedef struct s_player_pos
{
	int	pos[2];
}				t_player_pos;

typedef struct s_map
{
	uint			width;
	uint			height;
	char			**points;
	t_player_pos	*player;
}				t_map;

typedef struct s_texture
{
	int		width;
	int		height;
	void	*img;
	char	*file;
}				t_texture;

typedef struct s_textures
{
	int			ceiling;
	int			floor;
	t_texture	*wall_north;
	t_texture	*wall_south;
	t_texture	*wall_west;
	t_texture	*wall_east;
}				t_textures;

typedef struct s_img
{
	int		endian;
	int		line_length;
	int		bits_per_pixel;
	char	*addr;
	void	*img;
}				t_img;

typedef struct s_game
{
	t_map		*map;
	void		*mlx;
	void		*win;
	t_img		*img;
	t_textures	*textures;
	t_player	player;
}				t_game;

void		free_token(void *ptr);
void		free_game(t_game *game);
void		free_map(t_map *map);
void		free_points(char **points);

t_game		*init_game(void);
t_map		*init_map(void);
t_textures	*init_textures(void);

#endif
