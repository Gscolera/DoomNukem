#include "doom_nukem.h"

DN_ERROR	select_game_mode(ENGINE *doom)
{
	if (doom->mode == MAIN_MENU)
		show_main_menu(doom);
	else if (doom->mode == PAUSE)
		show_pause_menu(doom);
	else if (doom->mode == GAME)
		render(doom);
	else if (doom->mode == MAP_EDITOR)
	{
		run_editor();
		doom->mode = MAIN_MENU;
	}
	return (OK);
}
