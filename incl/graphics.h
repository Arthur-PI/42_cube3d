#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "mlx.h"
# include "struct.h"

# define WIN_WIDTH 1000
# define WIN_HEIGHT 500
# define WIN_TITLE "Cube3D"

int	load_textures(void *mlx, t_textures *textures);
int	init_graphics(t_game *game);

#endif