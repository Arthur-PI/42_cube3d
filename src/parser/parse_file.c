/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:12:55 by apigeon           #+#    #+#             */
/*   Updated: 2022/12/13 18:02:34 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	*get_token_name(t_token_type type)
{
	if (type == TOKEN_MAP)
		return ("MAP");
	else if (type == TOKEN_NORTH)
		return ("NORTH");
	else if (type == TOKEN_SOUTH)
		return ("SOUTH");
	else if (type == TOKEN_WEST)
		return ("WEST");
	else if (type == TOKEN_EAST)
		return ("EAST");
	else if (type == TOKEN_CEILING)
		return ("CEIL");
	else if (type == TOKEN_FLOOR)
		return ("FLOOR");
	return ("NONE");
}

static void	print_tokens(t_list *tokens)
{
	t_token	*token;

	while (tokens)
	{
		token = tokens->content;
		printf("Token (%s)\t-> %s\n", get_token_name(token->type), token->value);
		tokens = tokens->next;
	}
}

/* Parse a file into t_game structure and return it,
 * filename: the path to the file to parse,
 * returns: a pointer to a t_game struct
 */
void	*parse_file(const char *filename)
{
	char	*trim_name;
	t_list	*tokens;

	trim_name = ft_strtrim(filename, " \t");
	if (!trim_name)
		return (NULL);
	if (!valid_file(trim_name))
		return (free(trim_name), NULL);
	tokens = get_tokens(trim_name);
	if (tokens == NULL)
		return (err_message(MSG_ERROR_TOKEN), NULL);
	if (!valid_map(tokens))
		return (err_message(MSG_INVALID_MAP), NULL);
	print_tokens(tokens);
	ft_lstclear(&tokens, &free_token);
	free(trim_name);
	return (NULL);
}
