
#include "parser.h"

static bool	valid_filename(const char *filename)
{
	int	len;

	if (!filename)
		return (false);
	len = ft_strlen(filename);
	if (len < 5)
		return (false);
	if (ft_strcmp(filename + (len - 3 - 1), ".cub") != 0)
		return (false);
	return (true);
}

static bool	file_readable(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (false);
	if (read(fd, NULL, 0) == -1)
		return (close(fd), false);
	close(fd);
	return (true);
}

bool	valid_file(const char *filename)
{
	if (!valid_filename(filename))
		return (err_message(INVALID_FILENAME), false);
	if (!file_readable(filename))
		return (err_message(FILE_NOT_READABLE), false);
	return (true);
}
