/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_values.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:49:31 by apigeon           #+#    #+#             */
/*   Updated: 2022/12/16 22:49:34 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	valid_map_values(t_list *tokens)
{
	while (tokens && ((t_token *)tokens->content)->type != TOKEN_MAP)
		tokens = tokens->next;
	while (tokens && ((t_token *)tokens->content)->type == TOKEN_MAP)
		tokens = tokens->next;
	if (tokens)
		return (false);
	return (true);
}
