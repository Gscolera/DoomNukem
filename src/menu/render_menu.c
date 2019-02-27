#include "doom_nukem.h"

static void get_button_color(MENU *menu, U8 state)
{
	if (state == OPTIONS)
	{
		MENU_FCOLOR.r = 255;
		MENU_FCOLOR.g = 255;
		MENU_FCOLOR.b = 255;
	}
	else
	{
		MENU_FCOLOR.r = 125;
		MENU_FCOLOR.g = 125;
		MENU_FCOLOR.b = 125;
	}
}

void	render_menu(ENGINE *doom, MENU *menu)
{
	U8			i;
	SDL_Rect 	rect;

	i = 0;
	rect.x = WINDOW_WIDTH / 60;
	rect.y = WINDOW_HEIGHT * 0.5;
	draw_image(doom, MENU_IMG, NO_RECTS);
	while (i < 5)
	{
		get_button_color(menu, i);
		if (i == 0)
			MENU_BUTTON[i] = TTF_RenderText_Solid(MENU_FONT, "New Game", MENU_FCOLOR);
		else if (i == 1)
			MENU_BUTTON[i] = TTF_RenderText_Solid(MENU_FONT, "Save Game", MENU_FCOLOR);
		else if (i == 2)
			MENU_BUTTON[i] = TTF_RenderText_Solid(MENU_FONT, "Load Game", MENU_FCOLOR);
		else if (i == 3)
			MENU_BUTTON[i] = TTF_RenderText_Solid(MENU_FONT, "Level Editor", MENU_FCOLOR);
		else if (i == 4)
			MENU_BUTTON[i] = TTF_RenderText_Solid(MENU_FONT, "Exit", MENU_FCOLOR);
		rect.h = MENU_BUTTON[i]->h;
		rect.w = MENU_BUTTON[i]->w;
		rect.y += rect.h;
		SDL_BlitScaled(MENU_BUTTON[i], NULL, SCREEN, &rect);
		i++;
	}
	SDL_UpdateWindowSurface(WINDOW);

}