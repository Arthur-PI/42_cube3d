#include "struct.h"

// TODO free all xpm loaded textures with mlx_destroy_image
static void	free_texture(t_texture *textures)
{
	if (textures)
	{
		free(textures);
	}
}

void	free_game(t_game *game)
{
	if (game)
	{
		free_map(game->map);
		free_texture(game->textures);
		free(game);
	}
}
