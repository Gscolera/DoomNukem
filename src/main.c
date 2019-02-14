#include "doom_nukem.h"

DN_ERROR		main(void)
{
	ENGINE	doom;

	run_engine(&doom);
	while (doom.power)
	{
		
		run_game(&doom);
		parse_events(&doom);
		
	}
	free(doom.texture.logo->pixels);
	free(doom.texture.logo);
	stop_engine(&doom);
	exit(OK);
}