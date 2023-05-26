/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:49:39 by apigeon           #+#    #+#             */
/*   Updated: 2022/12/16 22:49:41 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	valid_texture(t_token *texture)
{
	(void)texture;
	return (true);
}

static bool	is_token_texture(t_token_type type)
{
	if (type == TOKEN_NORTH)
		return (true);
	else if (type == TOKEN_SOUTH)
		return (true);
	else if (type == TOKEN_WEST)
		return (true);
	else if (type == TOKEN_EAST)
		return (true);
	return (false);
}

bool	valid_textures(t_list *tokens)
{
	int		textures[4];
	uint	i;
	t_token	*token;

	ft_memset(textures, 0, sizeof(int) * 4);
	while (tokens)
	{
		token = tokens->content;
		if (is_token_texture(token->type))
		{
			if (!valid_texture(token))
				return (false);
			textures[token->type % 4] += 1;
			if (textures[token->type % 4] > 1)
				return (false);
		}
		tokens = tokens->next;
	}
	i = 0;
	while (i < 4)
		if (textures[i++] == 0)
			return (false);
	return (true);
}
