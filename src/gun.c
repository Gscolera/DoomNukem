#include "doom_nukem.h"

void	make_shot(ENGINE *doom)
{
	SHOT = 1;
	Mix_PlayChannel(-1, SHOT_SOUND, 0);
	GUN_FS = SDL_GetTicks();
}

void	load_gun_textures(ENGINE *doom)
{
	GUN.sprite = read_tga("images/gun.tga");
	CROSS = read_tga("images/cross.tga");
	GUN.frames = 2;	
}

void	draw_gun(ENGINE *doom)
{
	REND_IW = GUN.sprite->width / GUN.frames;
	REND_IH = GUN.sprite->height;
	DEFORMATION = (double)REND_IH / WINDOW_HEIGHT * 0.75;
	YI_OFFSET = 0;
	
	if (SHOT)
	{
		REND_SH = REND_IH * DEFORMATION * 1.03;
		REND_SW = REND_IW * DEFORMATION * 1.03;
		X_OFFSET = WINDOW_WIDTH * 0.65 - REND_SW / 2;
		Y_OFFSET = WINDOW_HEIGHT - REND_SH;
		XI_OFFSET = GUN.sprite->width / GUN.frames;
	}
	else
	{
		REND_SH = REND_IH * DEFORMATION;
		REND_SW = REND_IW * DEFORMATION;
		X_OFFSET = WINDOW_WIDTH * 0.65 - REND_SW / 2;
		Y_OFFSET = WINDOW_HEIGHT - REND_SH;
		XI_OFFSET = 0;
	}
	if (SHOT && SDL_GetTicks() - GUN_FS > 10)
		SHOT = 0;
	draw_image(doom, GUN.sprite, BOTH_RECTS);
	REND_SW = 30;
	REND_SH = 30;
	X_OFFSET = WINDOW_WIDTH * 0.5;
	Y_OFFSET = WINDOW_HEIGHT * 0.55;
	draw_image(doom, CROSS, SCREEN_RECT);

}