/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_wall_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:17:03 by apigeon           #+#    #+#             */
/*   Updated: 2022/12/29 19:17:04 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	is_wall_texture(t_token_type type)
{
	if (type == TOKEN_NORTH || type == TOKEN_SOUTH)
		return (true);
	if (type == TOKEN_WEST || type == TOKEN_EAST)
		return (true);
	return (false);
}
