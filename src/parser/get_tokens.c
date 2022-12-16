/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:06:59 by apigeon           #+#    #+#             */
/*   Updated: 2022/12/13 18:04:23 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* Return a t_list of tokens according to t_token and t_token_type,
 * filename: the path to filename to parse,
 * returns: a pointer to the the first token of the list
 * or return NULL if an error occured
 */
t_list	*get_tokens(const char *filename)
{
	int		fd;
	char	*line;
	t_list	*tokens;

	tokens = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (parse_line(&tokens, line) == ERROR_TOKEN)
		{
			free(line);
			close(fd);
			ft_lstclear(&tokens, &free_token);
			return (NULL);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (tokens);
}
