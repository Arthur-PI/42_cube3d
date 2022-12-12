/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:06:59 by apigeon           #+#    #+#             */
/*   Updated: 2022/12/12 19:42:30 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	parse_line(t_list **tokens, char *line)
{
	(void)tokens;
	(void)line;
	printf("%s", line);
	return (1);
}

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
		if (parse_line(&tokens, line) == -1)
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
