/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 21:57:46 by oaarsse           #+#    #+#             */
/*   Updated: 2023/05/05 23:13:29 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include <stdio.h>
# include <math.h>
# include <limits.h>
# include <float.h>
# include "libft.h"
# include "parser.h"
# include "graphics.h"
# include "constant.h"

void	init_raycast(t_game *game, int x);
void	init_rays(t_game *game);
void	dda(t_game *game);

#endif