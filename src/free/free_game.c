#include "struct.h"

static void	free_player(t_player *player)
{
	if (player)
	{
		free(player);
	}
}

static void	free_map(t_map *map)
{
	uint	i;

	if (map)
	{
		if (map->points)
		{
			i = 0;
			while (i < map->width)
				free(map->points[i++]);
			free(map->points);
		}
		free_player(map->player);
		free(map);
	}
}

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
