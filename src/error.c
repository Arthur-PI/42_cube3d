/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:56:14 by apigeon           #+#    #+#             */
/*   Updated: 2022/12/12 21:56:18 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	err_message(const char *s)
{
	printf("Error: %s\n", s);
}
