#ifndef STRUCT_H
# define STRUCT_H

# include <stdlib.h>
# include "mlx.h"

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

typedef struct s_token
{
	t_token_type	type;
	char			*value;
}				t_token;

typedef struct s_player
{
	int	pos[2];
}				t_player;

typedef struct s_map
{
	uint		width;
	uint		height;
	char		**points;
	t_player	*player;
}				t_map;

typedef struct s_texture
{
	void	*ceiling;
	void	*floor;
	void	*wall_north;
	void	*wall_south;
	void	*wall_west;
	void	*wall_east;
}				t_texture;

typedef struct s_game
{
	t_map		*map;
	t_texture	*textures;
}				t_game;

void	free_token(void *ptr);
void	free_game(t_game *game);

#endif