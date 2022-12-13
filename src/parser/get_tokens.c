/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:06:59 by apigeon           #+#    #+#             */
/*   Updated: 2022/12/13 16:13:47 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	is_info_token(const char *s)
{
	int		i;
	char	*info_symbols[6];

	info_symbols[0] = "NO";
	info_symbols[1] = "SO";
	info_symbols[2] = "WE";
	info_symbols[3] = "EA";
	info_symbols[4] = "C";
	info_symbols[5] = "F";
	i = 0;
	while (i < 6)
	{
		if (ft_strncmp(s, info_symbols[i], ft_strlen(info_symbols[i])) == 0)
			return (true);
		i++;
	}
	return (false);
}

static int	extract_info_tokens(t_list **tokens, const char *s)
{
	(void)s;
	(void)tokens;
	return (TOKEN_ERROR);
}

static int	extract_map_token(t_list **tokens, const char *s)
{
	(void)s;
	(void)tokens;
	return (TOKEN_ERROR);
}

static int	parse_line(t_list **tokens, char *line)
{
	int	i;
	(void)tokens;
	i = 0;
	while (line[i])
	{
		if (is_info_token(line + i))
		{
			if (extract_info_tokens(tokens, line + i) == TOKEN_ERROR)
				return (TOKEN_ERROR);
			return (TOKEN_GOOD);
		}
		i++;
	}
	if (extract_map_token(tokens, line) == TOKEN_ERROR)
		return (TOKEN_ERROR);
	return (TOKEN_GOOD);
}

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
		if (parse_line(&tokens, line) == TOKEN_ERROR)
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
