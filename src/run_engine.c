# include "doom_nukem.h"

static DN_ERROR	run_errors(ENGINE *doom, DN_ERROR error)
{
	if (error == SDL_ERROR)
	{
		write(1, "Unable to initialize SDL\n", 25);
		return (SDL_ERROR);
	}
	else
	{
		write(1, "Unable to load textures\n", 24);
		return (SDL_ERROR);
	}
}

static void	init_engine(ENGINE *doom)
{
	doom->mode = MAIN_MENU;
	GUN.sprite = NULL;
	CROSS = NULL;
	WINDOW = NULL;
	SCREEN = NULL;
	SHOT = false;
	WINDOW_WIDTH = START_WIDTH;
	WINDOW_HEIGHT = START_HEIGHT;
	doom->current_time = 0;
	doom->last_time = 0;
	doom->delta_time = 0;
}

static DN_ERROR	load_textures(ENGINE *doom)
{
	load_gun_textures(doom);
	return (OK);
}

DN_ERROR	run_engine(ENGINE *doom)
{
	init_engine(doom);
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		return (SDL_ERROR);
	if (!(WINDOW = SDL_CreateWindow("DoomNukem", SDL_WINDOWPOS_CENTERED,
												SDL_WINDOWPOS_CENTERED,
												WINDOW_WIDTH, WINDOW_HEIGHT,
												SDL_WINDOW_RESIZABLE)))
		return (run_errors(doom, SDL_ERROR));
	if (!(SCREEN = SDL_GetWindowSurface(WINDOW)))
		return(run_errors(doom, SDL_ERROR));
	if (load_textures(doom) != OK)
		return(run_errors(doom, IMAGE_ERROR));
	SDL_UpdateWindowSurface(WINDOW);
	Mix_Init(MIX_INIT_MP3);
	TTF_Init();
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
		perror(Mix_GetError());

	SCREEN_PTR = doom->window.screen->pixels;
	map_init(doom);
	if (!(SHOT_SOUND = Mix_LoadWAV("sounds/gunshot.wav")))
		perror(Mix_GetError());
	init_render(doom);
	MOUSE = true;
	hide_mouse(doom);
	return (OK);
}
