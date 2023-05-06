/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:13:14 by apigeon           #+#    #+#             */
/*   Updated: 2023/05/06 01:43:26 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>
# include "libft.h"
# include "struct.h"

void	trim_end(char *s);
void	print_game(t_game *game);
void	print_map(t_map *map);
bool	move_player(t_map *map, t_direction dir);
void	print_game_live(t_game *game, t_map *map, t_player player);

#endif
