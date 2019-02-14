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
	POWER = false;
	PAUSE = false;
	LOGO = NULL;
	WINDOW = NULL;
	SCREEN = NULL;
	WINDOW_WIDTH = START_WIDTH;
	WINDOW_HEIGHT = START_HEIGHT;
}

static DN_ERROR	load_textures(ENGINE *doom)
{
	if (!(LOGO = read_tga("images/logo.tga")))
		return (IMAGE_ERROR);
	return (OK);
}

DN_ERROR	run_engine(ENGINE *doom)
{
	init_engine(doom);
	if (SDL_Init(SDL_INIT_VIDEO) == -1)
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
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
	SCREEN_PTR = doom->window.screen->pixels;
	POWER = true;
	return (OK);
}