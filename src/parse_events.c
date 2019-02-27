#include "doom_nukem.h"

DN_ERROR	parse_events(ENGINE *doom)
{
	float psin;
	float pcos;

	psin = doom->player.anglesin;
	pcos = doom->player.anglecos;
	while (SDL_PollEvent(&EVENT))
	{
		if (ETYPE == SDL_QUIT)
			doom->mode = QUIT;
		if (ETYPE == SDL_KEYDOWN && KEY == SDLK_ESCAPE)
			doom->mode = PAUSE;
		
		if (ETYPE == SDL_MOUSEBUTTONDOWN && BUTTON == SDL_BUTTON_LEFT)
			make_shot(doom);
		if (ETYPE == SDL_KEYDOWN && KEY == SDLK_p)
			make_shot(doom);
		if (ETYPE == SDL_KEYDOWN && KEY == SDLK_w)
			move_player(doom, pcos, psin);
		if (ETYPE == SDL_KEYDOWN && KEY == SDLK_s)
			move_player(doom, -pcos, -psin);
		if (ETYPE == SDL_KEYDOWN && KEY == SDLK_a)
			move_player(doom, psin, -pcos);
		if (ETYPE == SDL_KEYDOWN && KEY == SDLK_d)
			move_player(doom, -psin, pcos);
		if (ETYPE == SDL_KEYDOWN && KEY == SDLK_LALT)
			(MOUSE) ? hide_mouse(doom) : show_mouse(doom);
	}
	mouse_control(doom);
	return (OK);
}
