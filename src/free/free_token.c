/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:28:59 by apigeon           #+#    #+#             */
/*   Updated: 2022/12/13 16:13:55 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* Free all the memory held by the t_token in the pointer,
 * ptr: the pointer to the t_token structure
 */
void	free_token(void *ptr)
{
	t_token	*token;
	
	if (ptr)
	{
		token = ptr;
		free(token->value);
		free(ptr);
	}
}
