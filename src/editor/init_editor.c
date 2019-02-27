#include "editor.h"

static void	create_editor_window(EDITOR *editor)
{
	EWW = ED_WIN_WIDTH;
	EWH = ED_WIN_HEIGHT;
	EDITOR_WINDOW = SDL_CreateWindow("Map Editor", SDL_WINDOWPOS_CENTERED,
													SDL_WINDOWPOS_CENTERED,
													EWW, EWH,
													SDL_WINDOW_BORDERLESS);
	if (!EDITOR_WINDOW)
		exit (EDITOR_SDL_ERROR);
	EDITOR_SCREEN = SDL_GetWindowSurface(EDITOR_WINDOW);
	if (!EDITOR_SCREEN)
		exit (EDITOR_SDL_ERROR);
	SDL_UpdateWindowSurface(EDITOR_WINDOW);
}

void	init_editor(EDITOR *editor)
{
	SECTOR = NULL;
	ACTIVE_SECTOR = NULL;
	ACTIVE_POINT = NULL;
	UNIQUE_LIST = NULL;
	SECTOR_AMOUNT = 0;
	create_editor_window(editor);
	init_working_surface(editor);
	init_bar(editor);
	printf("bar inted\n");
	EDITOR_SPTR = (Uint32 *)EDITOR_SCREEN->pixels;
	ESTATE = EDITOR_RUNNING;
	SDL_ShowCursor(SDL_TRUE);
	SDL_SetRelativeMouseMode(SDL_DISABLE);	
}