# include "doom_nukem.h"

static DN_ERROR	init_menu(ENGINE *doom, P_MENU *menu)
{
	MENU_FONT_SIZE = WINDOW_HEIGHT / 20;
	if (!(MENU_IMG = take_screenshot(doom)))
		return (MEMORY_ERROR);
	if (!(MENU_FONT = TTF_OpenFont("fonts/14611.otf", MENU_FONT_SIZE)))
		return(IMAGE_ERROR);
	if (!(MENU_MV_SOUND = Mix_LoadWAV("src/menu/sounds/move.wav")))
		return(SOUND_ERROR);
	if (!(MENU_CH_SOUND = Mix_LoadWAV("src/menu/sounds/choose.wav")))
		return(SOUND_ERROR);
	if (!(MENU_BGMUSIC = Mix_LoadMUS("src/menu/sounds/Menu_bg.mp3")))
		return(SOUND_ERROR);
	Mix_VolumeMusic(40);
	Mix_VolumeChunk(MENU_MV_SOUND, 100);
	Mix_PlayMusic(MENU_BGMUSIC, -1);
	OPTIONS = RESUME_GAME;
	return (OK);
}

static void		free_sources(P_MENU *menu)
{
	U32 i;

	i = 0;
	free(MENU_IMG->pixels);
	free(MENU_IMG);
	TTF_CloseFont(MENU_FONT);
	while (i < 4)
		SDL_FreeSurface(MENU_BUTTON[i++]);
	Mix_HaltChannel(-1);
	Mix_FreeMusic(MENU_BGMUSIC);
	Mix_FreeChunk(MENU_MV_SOUND);
	Mix_FreeChunk(MENU_CH_SOUND);
	

}

static void		parse_pmenu_events(ENGINE *doom, P_MENU *menu)
{
	while (SDL_PollEvent(&EVENT))
	{
		if (ETYPE == SDL_KEYDOWN && (KEY == SDLK_UP || KEY == SDLK_DOWN))
		{
			if (KEY == SDLK_DOWN)
				OPTIONS = ((OPTIONS == 3) ? 0 : OPTIONS + 1);
			else
				OPTIONS = ((OPTIONS == 0) ? 3 : OPTIONS - 1);
			Mix_PlayChannel(-1, MENU_MV_SOUND, 0);
			render_pause_menu(doom, menu);
		}
		if (ETYPE == SDL_KEYDOWN && KEY == SDLK_RETURN)
		{
			Mix_PlayChannel(-1, MENU_CH_SOUND, 0);
			if (OPTIONS == TO_MAIN_MENU)
				doom->mode = MAIN_MENU;
			else if (OPTIONS == RESUME_GAME)
				doom->mode = GAME;
		}
	}
}

DN_ERROR		show_pause_menu(ENGINE *doom)
{
	P_MENU	menu;

	if (init_menu(doom, &menu) != OK)
		return (MEMORY_ERROR);
	render_pause_menu(doom, &menu);
	while (doom->mode == PAUSE)
		parse_pmenu_events(doom, &menu);
	free_sources(&menu);
	return (OK);
}