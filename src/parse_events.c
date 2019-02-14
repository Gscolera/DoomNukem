#include "doom_nukem.h"

DN_ERROR	parse_events(ENGINE *doom)
{

	while (SDL_PollEvent(&EVENT))
	{
		if (ETYPE == SDL_QUIT || (ETYPE == SDL_KEYDOWN && KEY == SDLK_ESCAPE))
			doom->power = false;
		if (ETYPE == SDL_KEYDOWN && KEY == SDLK_TAB)
			PAUSE = true;
	}
	return (OK);
}