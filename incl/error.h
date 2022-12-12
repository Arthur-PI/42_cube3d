#ifndef ERROR_H
# define ERROR_H

# include <stdio.h>

# define INVALID_FILENAME "The map filename is not valid, only .cub accepted"
# define FILE_NOT_READABLE "Can't open the file"

void	err_message(const char *s);

#endif
