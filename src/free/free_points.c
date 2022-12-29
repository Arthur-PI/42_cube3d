/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:47:50 by apigeon           #+#    #+#             */
/*   Updated: 2022/12/29 17:47:51 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
