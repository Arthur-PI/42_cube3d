/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 20:54:25 by apigeon           #+#    #+#             */
/*   Updated: 2022/12/16 20:54:27 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	valid_map(t_list *tokens)
{
	if (!valid_textures(tokens))
		return (false);
	if (!valid_colors(tokens))
		return (false);
	if (!valid_map_values(tokens))
		return (false);
	return (true);
}
