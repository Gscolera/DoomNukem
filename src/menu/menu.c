#include "doom_nukem.h"

static void	free_sources(MENU *menu)
{
	U32 i;

	i = 0;
	free(MENU_IMG->pixels);
	free(MENU_IMG);
	while (i < 2)
	{
		free(MENU_BUTTON[i]->pixels);
		free(MENU_BUTTON[i++]);
	}
	Mix_HaltChannel(-1);
	Mix_FreeMusic(MENU_BGMUSIC);
	Mix_FreeChunk(MENU_MV_SOUND);
	Mix_FreeChunk(MENU_CH_SOUND);
}

static void	parse_menu_events(ENGINE *doom, MENU *menu)
{
	while (SDL_PollEvent(&EVENT))
	{
		if (ETYPE == SDL_KEYDOWN && KEY == SDLK_TAB)
			PAUSE = false;
		if (ETYPE == SDL_KEYDOWN && (KEY == SDLK_UP || KEY == SDLK_DOWN))
		{
			clear_window(doom);
			OPTIONS = ((OPTIONS == 1) ? 0 : 1);
			Mix_PlayChannel(-1, MENU_MV_SOUND, 0);
		}
		if (ETYPE == SDL_KEYDOWN && KEY == SDLK_KP_ENTER)
		{
			Mix_PlayChannel(-1, MENU_CH_SOUND, 0);
			if (OPTIONS == EXIT)
			{
				PAUSE = false;
				POWER = false;
			}
		}
	}
}

static DN_ERROR	init_menu(MENU *menu)
{
	if (!(MENU_IMG = read_tga("src/menu/images/logo.tga")))
		return(IMAGE_ERROR);
	if (!(MENU_BUTTON[0] = read_tga("src/menu/images/button1.tga")))
		return(IMAGE_ERROR);
	if (!(MENU_BUTTON[1] = read_tga("src/menu/images/button2.tga")))
		return(IMAGE_ERROR);
	if (!(MENU_MV_SOUND = Mix_LoadWAV("src/menu/sounds/move.wav")))
		return(SOUND_ERROR);
	if (!(MENU_CH_SOUND = Mix_LoadWAV("src/menu/sounds/choose.wav")))
		return(SOUND_ERROR);
	if (!(MENU_BGMUSIC = Mix_LoadMUS("src/menu/sounds/Menu_bg.mp3")))
		return(SOUND_ERROR);

	Mix_VolumeMusic(20);
	Mix_VolumeChunk(MENU_MV_SOUND, 100);
	Mix_PlayMusic(MENU_BGMUSIC, -1);
	OPTIONS = NEW_GAME;
	return (OK);
}

static void	render_menu(ENGINE *doom, MENU *menu)
{
	SDL_Rect 	rect;
	U32			i;

	i = 0;
	REND_SH = WINDOW_HEIGHT / 5;
	REND_SW = MENU_IMG->width / 2;
	X_OFFSET = WINDOW_WIDTH / 2 - REND_SW / 2;
	Y_OFFSET = 0;
	draw_image(doom, MENU_IMG, SCREEN_RECT);
	Y_OFFSET += WINDOW_HEIGHT / 5;
	while (i < 2)
	{
		REND_SH = ((i == OPTIONS) ? MENU_BUTTON[i]->height * 1.25 : MENU_BUTTON[i]->height);
		REND_SW = ((i == OPTIONS) ? MENU_BUTTON[i]->width * 1.25 : MENU_BUTTON[i]->width);
		X_OFFSET = WINDOW_WIDTH / 2 - REND_SW / 2;
		Y_OFFSET += WINDOW_HEIGHT / 5;
		draw_image(doom, MENU_BUTTON[i], SCREEN_RECT);
		i++;
	}
}

DN_ERROR	show_menu(ENGINE *doom)
{
	MENU		menu;

	if (init_menu(&menu) != OK)
		return (SOUND_ERROR);
	while (PAUSE)
	{
		
		render_menu(doom, &menu);
		parse_menu_events(doom, &menu);
		
	}
	free_sources(&menu);
	return (OK);
}