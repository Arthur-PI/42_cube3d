#include "graphics.h"

static int	load_texture(void *mlx, t_texture *t)
{
	t->img = mlx_xpm_file_to_image(mlx, t->file, &t->width, &t->height);
	if (!t->img)
		return (DEBUG(MSG_ERROR_XPM_LOAD), -1);
	return (1);
}

int	load_textures(void *mlx, t_textures *textures)
{
	if (load_texture(mlx, textures->wall_north) == -1)
		return (DEBUG("can't load north wall texture"), -1);
	if (load_texture(mlx, textures->wall_south) == -1)
		return (DEBUG("can't load south wall texture"), -1);
	if (load_texture(mlx, textures->wall_west) == -1)
		return (DEBUG("can't load west wall texture"), -1);
	if (load_texture(mlx, textures->wall_east) == -1)
		return (DEBUG("can't load east wall texture"), -1);
	return (1);
}
