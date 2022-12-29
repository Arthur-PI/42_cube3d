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

# define MSG_INVALID_FILENAME "The map filename is invalid, only .cub accepted."
# define MSG_FILE_NOT_READABLE "Can't open the file."
# define MSG_MALLOC_ERROR "can't allocate memory. "
# define MSG_CANT_OPEN "file invalid (does not exist or wrong permissions)"
# define MSG_ERROR_TOKEN "can't parse the file into tokens, format invalid"
# define MSG_INVALID_MAP "the map data is invalid please check your file"
# define MSG_ERROR_MAP "can't parse the tokens into a map"
# define MSG_INVALID_COLOR "colors must be between 0 and 255"

void	err_message(const char *s);

#endif
