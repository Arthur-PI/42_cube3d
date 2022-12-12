/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:12:55 by apigeon           #+#    #+#             */
/*   Updated: 2022/12/12 21:55:49 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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
	ft_lstclear(&tokens, &free_token);
	free(trim_name);
	return (NULL);
}
