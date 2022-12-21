#include "parser.h"

void	free_points(char **points)
{
	uint	i;

	if (points)
	{
		i = 0;
		while (points[i])
			free(points[i++]);
		free(points);
	}
}
