#include "doom_nukem.h"

static void set_rect_values(ENGINE *doom, IMAGE *image, U8 flag)
{
	if (flag != IMAGE_RECT)
	{
		XI_OFFSET = 0;
		YI_OFFSET = 0;
		REND_IH = image->height;
		REND_IW = image->width;
	}
	if (flag != SCREEN_RECT)
	{
		X_OFFSET = 0;
		Y_OFFSET = 0;
		REND_SH = WINDOW_HEIGHT;
		REND_SW = WINDOW_WIDTH;
	}
}

void	draw_image(ENGINE *doom, IMAGE *image, U8 flag)
{
	X = 0;
	if (flag != BOTH_RECTS)
		set_rect_values(doom, image, flag);
	while (X < REND_SW)
	{
		Y = 0;
		TEXX = (double)REND_IW / REND_SW * X + XI_OFFSET;
		while (Y < REND_SH)
		{
			TEXY = (double)REND_IH / REND_SH * Y + YI_OFFSET;
			COLOR = image->pixels[TEXY * image->width + TEXX];
			if (COLOR  & 0xFF000000)
				SCREEN_PTR[(Y + Y_OFFSET) * WINDOW_WIDTH + X + X_OFFSET] = COLOR;
			Y++;
		}
		X++;
	}
	SDL_UpdateWindowSurface(WINDOW);
}

void	clear_window(ENGINE *doom)
{
	U32 i;
	U32 size;

	i = 0;
	size = WINDOW_HEIGHT * WINDOW_WIDTH;
	while (i < size)
		SCREEN_PTR[i++] = 0;
	SDL_UpdateWindowSurface(WINDOW);
}