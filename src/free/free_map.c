#include "struct.h"

static void	free_player(t_player *player)
{
	if (player)
	{
		free(player);
	}
}

void	free_map(t_map *map)
{
	if (map)
	{
		free_points(map->points);
		free_player(map->player);
		free(map);
	}
}
