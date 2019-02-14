#include "doom_nukem.h"

DN_ERROR	run_game(ENGINE *doom)
{
	if (PAUSE)
		show_menu(doom);
	clear_window(doom);
	return (OK);
}