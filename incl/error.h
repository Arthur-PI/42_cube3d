/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:09:16 by apigeon           #+#    #+#             */
/*   Updated: 2022/12/13 18:42:07 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <stdio.h>

# ifdef DEBUG_MODE
#  define DEBUG(msg) (printf("[DEBUG %s@%d] %s \n", __FILE__, __LINE__, msg))
# else
#  define DEBUG(msg) (NULL)
# endif

# define MIN(X,Y) ((X) < (Y) ? (X) : (Y))

# define INVALID_FILENAME "The map filename is not valid, only .cub accepted."
# define FILE_NOT_READABLE "Can't open the file."
# define MALLOC_ERROR "can't allocate memory. "
# define MSG_CANT_OPEN "file invalid (does not exist or wrong permissions)"

void	err_message(const char *s);

#endif
