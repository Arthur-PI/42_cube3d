/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:10:26 by apigeon           #+#    #+#             */
/*   Updated: 2023/05/05 21:56:07 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

void	reverse_string(char *s, uint len)
{
	char	tmp;
	uint		i;

	i = 0;
	while (i < len / 2)
	{
		tmp = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = tmp;
		i++;
	}
}
