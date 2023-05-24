/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 23:30:50 by oaarsse           #+#    #+#             */
/*   Updated: 2023/05/06 00:40:07 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include "constant.h"
# include "cube3d.h"
# include "engine.h"

void	setup_hooks(t_game *game);
int		game_loop(t_game *game);
void	exec_player_movements(t_game *game);
void	exec_player_rotations(t_game *game);

#endif