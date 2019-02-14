#include "doom_nukem.h"

DN_ERROR	stop_engine(ENGINE *doom)
{
	SDL_DestroyWindow(WINDOW);
	SDL_Quit();
	return (OK);
}