/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:49:24 by apigeon           #+#    #+#             */
/*   Updated: 2022/12/16 22:49:27 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	check_color(char *color)
{
	uint	i;
	uint	nb_comma;

	i = 0;
	nb_comma = 0;
	while (color[i])
	{
		if (color[i] == ',')
			nb_comma++;
		else if (!ft_isdigit(color[i]))
			return (DEBUG("invalid floor or ceiling color"), false);
		i++;
	}
	if (nb_comma != 2)
		return (DEBUG("invalid floor or ceiling color"), false);
	return (true);
}

bool	valid_colors(t_list *tokens)
{
	uint	i;
	int		colors[2];
	t_token	*token;

	ft_memset(colors, 0, 2 * sizeof(int));
	while (tokens)
	{
		token = tokens->content;
		if (token->type == TOKEN_CEILING || token->type == TOKEN_FLOOR)
		{
			if (!check_color(token->value))
				return (false);
			colors[token->type % 2] += 1;
			if (colors[token->type % 2] > 1)
				return (DEBUG("ceiling or floor color duplicate"), NULL);
		}
		tokens = tokens->next;
	}
	i = 0;
	while (i < 2)
		if (colors[i++] == 0)
			return (DEBUG("ceiling or floor color missing"), NULL);
	return (true);
}
