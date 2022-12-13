/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:50:22 by apigeon           #+#    #+#             */
/*   Updated: 2022/12/13 18:06:01 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_token	*create_token(char *s, t_token_type type)
{
	int		len;
	t_token	*token;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (len > 0 && s[len - 1] == '\n')
		s[len - 1] = 0;
	token = malloc(sizeof(*token));
	if (!token)
		return (NULL);
	token->type = type;
	token->value = s;
	return (token);
}
