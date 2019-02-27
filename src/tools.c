# include "doom_nukem.h"

IMAGE		*take_screenshot(ENGINE *doom)
{
	IMAGE	*shot;
	int		i;
	int		length;

	if (!(shot = (IMAGE *)malloc(sizeof(IMAGE))))
		return (NULL);
	shot->height = WINDOW_HEIGHT;
	shot->width = WINDOW_WIDTH;
	shot->pixels = (U32 *)malloc(sizeof(U32) * shot->width * shot->height);
	if (!shot->pixels)
		return (NULL);
	i = -1;
	length = WINDOW_HEIGHT * WINDOW_WIDTH;
	while (++i < length)
		shot->pixels[i] = SCREEN_PTR[i];
	return (shot);
}