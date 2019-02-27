#include "doom_nukem.h"

static DN_ERROR	init_menu(ENGINE *doom, MENU *menu)
{
	MENU_FONT_SIZE = WINDOW_HEIGHT / 20;
	if (!(MENU_IMG = read_tga("src/menu/images/MenuBackGround.tga")))
		return(IMAGE_ERROR);
	if (!(MENU_FONT = TTF_OpenFont("fonts/14611.otf", MENU_FONT_SIZE)))
		return(IMAGE_ERROR);
	/*if (!(MENU_MV_SOUND = Mix_LoadWAV("src/menu/sounds/move.wav")))
		return(OK);
	if (!(MENU_CH_SOUND = Mix_LoadWAV("src/menu/sounds/choose.wav")))
		return(OK);
	if (!(MENU_BGMUSIC = Mix_LoadMUS("src/menu/sounds/Menu_bg.mp3")))
		return(OK);*/
	//Mix_VolumeMusic(40);
	//Mix_VolumeChunk(MENU_MV_SOUND, 100);
	//Mix_PlayMusic(MENU_BGMUSIC, -1);
	OPTIONS = NEW_GAME;
	return (OK);
}

static void	parse_menu_events(ENGINE *doom, MENU *menu)
{
	while (SDL_PollEvent(&EVENT))
	{
		if (ETYPE == SDL_KEYDOWN && (KEY == SDLK_UP || KEY == SDLK_DOWN))
		{
			if (KEY == SDLK_DOWN)
				OPTIONS = ((OPTIONS == 4) ? 0 : OPTIONS + 1);
			else
				OPTIONS = ((OPTIONS == 0) ? 4 : OPTIONS - 1);
			//Mix_PlayChannel(-1, MENU_MV_SOUND, 0);
			render_menu(doom, menu);
		}
		if (ETYPE == SDL_KEYDOWN && KEY == SDLK_RETURN)
		{
			//Mix_PlayChannel(-1, MENU_CH_SOUND, 0);
			if (OPTIONS == EXIT)
				doom->mode = QUIT;
			else if (OPTIONS == NEW_GAME)
				doom->mode = GAME;
			else if (OPTIONS == LEVEL_EDITOR)
				doom->mode = MAP_EDITOR;
		}
	}
}

static void	free_sources(MENU *menu)
{
	U32 i;

	i = 0;
	free(MENU_IMG->pixels);
	free(MENU_IMG);
	TTF_CloseFont(MENU_FONT);
	while (i < 5)
		SDL_FreeSurface(MENU_BUTTON[i++]);
	/*Mix_HaltChannel(-1);
	Mix_FreeMusic(MENU_BGMUSIC);
	Mix_FreeChunk(MENU_MV_SOUND);
	Mix_FreeChunk(MENU_CH_SOUND);*/
}

DN_ERROR	show_main_menu(ENGINE *doom)
{
	MENU		menu;

	if (init_menu(doom, &menu) != OK)
		exit(MENU_ERROR);
	render_menu(doom, &menu);
	while (doom->mode == MAIN_MENU)
		parse_menu_events(doom, &menu);
	free_sources(&menu);
	return (OK);
}
