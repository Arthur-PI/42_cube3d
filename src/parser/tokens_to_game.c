/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_to_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:48:41 by apigeon           #+#    #+#             */
/*   Updated: 2022/12/29 17:48:42 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_game	*tokens_to_game(t_list *tokens)
{
	t_game	*game;

	game = init_game();
	if (!game)
		return (NULL);
	game->map = get_map(tokens);
	game->textures = get_textures(tokens);
	if (!game->map || !game->textures)
		return (free_game(game), NULL);
	if (!can_escape_map(game->map))
		return (free_game(game), NULL);
	return (game);
}
