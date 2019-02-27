#include "doom_nukem.h"

int		main(void)
{
	ENGINE	doom;

	run_engine(&doom);
	while (doom.mode != QUIT)
	{
		select_game_mode(&doom);
		count_delta_time(&doom);
		parse_events(&doom);
	}
	stop_engine(&doom);
	exit(OK);
}
