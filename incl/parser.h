/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:13:14 by apigeon           #+#    #+#             */
/*   Updated: 2022/12/13 17:10:01 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"
# include "error.h"
# include "struct.h"

# define GOOD 1
# define ERROR_TOKEN -1

# define MAX(a, b) ((a) < (b) ? (b) : (a))

void		*parse_file(const char *filename);
t_list		*get_tokens(const char *filename);
t_token		*create_token(char *s, t_token_type type);
bool		valid_file(const char *filename);
bool		valid_map(t_list *tokens);
bool		valid_map_values(t_list *tokens);
bool		valid_textures(t_list *tokens);
bool		valid_colors(t_list *tokens);
int			parse_line(t_list **tokens, char *line);
t_game		*tokens_to_game(t_list *tokens);
bool		can_escape_map(t_map *map);
t_map		*get_map(t_list *tokens);
t_textures	*get_textures(t_list *tokens);

#endif
