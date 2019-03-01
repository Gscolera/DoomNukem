#include "editor.h"

void	init_working_surface(EDITOR *editor)
{
	
	WS = SDL_CreateRGBSurface(0, WS_WIDTH, WS_HEIGHT, 32, 0, 0, 0, 0);
	if (!WS)
		exit(EDITOR_MEMORY_ERROR);
	WS_RECT.w = EWW;
	WS_RECT.h = EWH;
	WS_RECT.x = 0;
	WS_RECT.y = 0;
	WS_POS.h = EWH;
	WS_POS.w = EWW;
	WS_POS.x = 0;
	WS_POS.y = 0;
	WS_PTR = (Uint32 *)WS->pixels;
	WS_UPDATED = false;
	draw_working_surface(WS);
	
}

void	draw_working_surface(SDL_Surface *working_surface)
{
	Sint16 	x;
	Sint16 	y;
	Uint32	*ptr;

	x = -1;
	ptr = (Uint32 *)working_surface->pixels;
	while (++x < working_surface->w)
	{
		y = -1;
		while (++y < working_surface->h)
		{
			if (x % GRID_SIZE == 0 || y % GRID_SIZE == 0)
				ptr[x + y * working_surface->w] = 0x6d5f03;
			else
				ptr[x + y * working_surface->w] = 0x18253a;
		}
	}
}

void	update_working_surface(EDITOR *editor)
{
	draw_working_surface(WS);
	draw_points(editor);
	SDL_BlitSurface(WS, &WS_RECT, EDITOR_SCREEN, &WS_POS);
	WS_UPDATED = true;
}