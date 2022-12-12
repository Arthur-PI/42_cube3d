/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:12:55 by apigeon           #+#    #+#             */
/*   Updated: 2022/12/12 18:58:31 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	*parse_file(const char *filename)
{
	char	*trim_name;

	trim_name = ft_strtrim(filename, " \t");
	if (!trim_name)
		return (NULL);
	if (!valid_file(trim_name))
		return (free(trim_name), NULL);
	free(trim_name);
	return (NULL);
}
