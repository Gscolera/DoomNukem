#include "tga_reader.h"

bool	open_error(char *path)
{
	perror(path);
	return (0);
}

bool	mem_error(TGA *tga)
{
	write(1, "Unable to allocate memory\n", 26);
	if (tga->data)
		free(tga->data);
	return (0);
}