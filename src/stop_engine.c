#include "doom_nukem.h"

static void free_textures(ENGINE *doom)
{
	if (GUN.sprite)
		free_image(GUN.sprite);
	if (CROSS)
		free_image(CROSS);
}

DN_ERROR	stop_engine(ENGINE *doom)
{
	Mix_FreeChunk(SHOT_SOUND);
	free_textures(doom);
	TTF_Quit();
	Mix_Quit();
	SDL_DestroyWindow(WINDOW);
	SDL_Quit();
	return (OK);
}