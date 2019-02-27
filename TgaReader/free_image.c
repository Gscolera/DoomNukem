#include "tga_reader.h"

void	free_image(IMAGE *image)
{
	free(image->pixels);
	image->pixels = NULL;
	free(image);
	image = NULL;
}