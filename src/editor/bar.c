# include "editor.h"

void	clear_surface(SDL_Surface *surface, Uint32 color)
{
	Uint32	*ptr;
	Sint16	x;
	Sint16	y;

	x = -1;
	ptr = (Uint32 *)surface->pixels;
	while (++x < surface->w)
	{
		y = -1;
		while (++y < surface->h)
			ptr[x + y * surface->w] = color;
	}
}

void	init_bar(EDITOR *editor)
{
	Uint16	width;
	Uint16	height;

	height = EWH;
	width = EWW / 8;
	BAR.updated = true;
	BAR.activated = false;
	BAR.bar = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
	BAR.font = TTF_OpenFont("fonts/Qonquer.ttf", 20);
	BAR.text_color.r = 146;
	BAR.text_color.g = 155;
	BAR.text_color.b = 154;
	BAR.header_color.r = 188;
	BAR.header_color.g = 157;
	BAR.header_color.b = 20;
	clear_surface(BAR.bar, BAR_COLOR);
}

void		activate_bar(EDITOR *editor)
{
	if (BAR.activated)
	{
		BAR.activated = false;
		WS_RECT.w += BAR.bar->w;
		WS_POS.w = WS_RECT.w;
		WS_POS.x = 0;
		WS_UPDATED = false;
	}
	else
	{
		BAR.activated = true;
		WS_RECT.w -= BAR.bar->w;
		WS_POS.w = WS_RECT.w;
		WS_POS.x = BAR.bar->w;
		WS_UPDATED = false;
		SDL_BlitSurface(BAR.bar, NULL, EDITOR_SCREEN, NULL);
	}
}

void		update_bar(EDITOR *editor)
{
	clear_surface(BAR.bar, BAR_COLOR);
	print_active_surface(editor);
	SDL_BlitSurface(BAR.bar, NULL, EDITOR_SCREEN, NULL);
	SDL_UpdateWindowSurface(EDITOR_WINDOW);
	BAR.updated = true;
}

