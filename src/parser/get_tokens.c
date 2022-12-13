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

#include "error.h"
#include "libft.h"
#include "parser.h"

static t_token_type	get_token_type(const char *s)
{
	if (ft_strncmp(s, "NO ", 3) == 0)
		return (TOKEN_NORTH);
	else if (ft_strncmp(s, "SO ", 3) == 0)
		return (TOKEN_SOUTH);
	else if (ft_strncmp(s, "WE ", 3) == 0)
		return (TOKEN_WEST);
	else if (ft_strncmp(s, "EA ", 3) == 0)
		return (TOKEN_EAST);
	else if (ft_strncmp(s, "C ", 2) == 0)
		return (TOKEN_CEILING);
	else if (ft_strncmp(s, "F ", 2) == 0)
		return (TOKEN_FLOOR);
	return (TOKEN_UNDIFINED);
}

static int	extract_info_tokens(t_list **tokens, const char *s)
{
	uint			i;
	uint			len;
	t_token			*token;
	t_list			*el;
	t_token_type	type;

	type = get_token_type(s);
	if (type == TOKEN_UNDIFINED)
		return (DEBUG("token info is undifined"), ERROR_TOKEN);
	i = 0;
	while (s[i] && s[i] != ' ')
		i++;
	while (s[i] && s[i] == ' ')
		i++;
	len = ft_strlen(s) - i;
	if (len == 0)
		return (DEBUG("info token empty !"), ERROR_TOKEN);
	token = create_token(ft_substr(s, i, len), type);
	if (!token)
		return (DEBUG("malloc error"), ERROR_TOKEN);
	el = ft_lstnew(token);
	if (!el)
		return (DEBUG("malloc error"), free_token(token), ERROR_TOKEN);
	ft_lstadd_back(tokens, el);
	return (GOOD);
}

static bool	is_map_char(int c)
{
	if (c == '0' || c == '1')
		return (true);
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (true);
	if (ft_isspace(c))
		return (true);
	return (false);
}

static int	extract_map_token(t_list **tokens, const char *s)
{
	int		i;
	t_token	*token;
	t_list	*el;

	i = 0;
	while (s[i])
	{
		if (!is_map_char(s[i]))
			return (DEBUG("token map format not valid"), ERROR_TOKEN);
		i++;
	}
	token = create_token(ft_strdup(s), TOKEN_MAP);
	if (!token)
		return (DEBUG("malloc error"), ERROR_TOKEN);
	el = ft_lstnew(token);
	if (!el)
		return (DEBUG("malloc error"), free_token(token), ERROR_TOKEN);
	ft_lstadd_back(tokens, el);
	return (GOOD);
}

static int	parse_line(t_list **tokens, char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (get_token_type(line + i) != TOKEN_UNDIFINED)
	{
		if (extract_info_tokens(tokens, line + i) == ERROR_TOKEN)
			return (ERROR_TOKEN);
		return (GOOD);
	}
	if (line[i] && extract_map_token(tokens, line) == ERROR_TOKEN)
		return (ERROR_TOKEN);
	return (GOOD);
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
