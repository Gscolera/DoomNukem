#include "doom_nukem.h"

static bool	is_arrow_key(int key)
{
	return (key == SDLK_RIGHT || 
			key == SDLK_LEFT || 
			key == SDLK_UP ||
			key == SDLK_DOWN);
}

static void	move_grid(EDITOR *editor, int key)
{
	if (key == SDLK_RIGHT && WS_RECT.x < WS_WIDTH - EWW)
		WS_RECT.x += 10;
	else if (key == SDLK_LEFT && WS_RECT.x > 0)
		WS_RECT.x -= 10;
	else if (key == SDLK_DOWN && WS_RECT.y < WS_HEIGHT - EWH)
		WS_RECT.y += 10;
	else if (key == SDLK_UP && WS_RECT.y > 0)
		WS_RECT.y -= 10;
	WS_UPDATED = false;
	BAR.updated = false;
}

void		editor_parse_events(EDITOR *editor)
{
	SDL_Event		e;
	const Uint8		*keystate;

	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
			ESTATE = EDITOR_EXIT_SUCCESS;
		if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_ESCAPE)
			ESTATE =  EDITOR_EXIT_SUCCESS;
		if (e.type == SDL_KEYDOWN && is_arrow_key(e.key.keysym.sym))
			move_grid(editor, e.key.keysym.sym);
		if (e.type ==  SDL_MOUSEBUTTONDOWN)
		{
			keystate = SDL_GetKeyboardState(NULL);
			if (keystate[SDL_SCANCODE_LCTRL])
					add_point(editor);
	 		// else
		 	// 	ACTIVE_POINT = point_nearby(editor, ACTIVE_SECTOR);	
		}
		if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_b)
		{
			keystate = SDL_GetKeyboardState(NULL);
			if (keystate[SDL_SCANCODE_LCTRL])
				activate_bar(editor);
			BAR.mode = SECTOR_MODE;
		}
	}
}
