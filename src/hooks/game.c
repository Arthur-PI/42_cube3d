/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 00:34:12 by oaarsse           #+#    #+#             */
/*   Updated: 2023/05/06 00:41:15 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

int	game_loop(t_game *game)
{
	exec_player_movements(game);
	exec_player_rotations(game);
	render(game);
	return (0);
}
