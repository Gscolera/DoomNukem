#ifndef DOOM_NUKEM_H
# define DOOM_NUKEM_H

# ifdef __linux__
#  include <SDL2/SDL.h>
#  include <SDL2/SDL_mixer.h>
# else
#  include "SDL.h"
#  include "SDL_mixer.h"
# endif

# include "definitions.h"
# include "tga_reader.h"
# include "menu.h"

typedef enum		e_error
{
	OK,
	MEMORY_ERROR,
	IMAGE_ERROR,
	SDL_ERROR,
	SOUND_ERROR
}					t_error;

typedef	struct		s_renderer
{
	SDL_Rect		screen;
	SDL_Rect		image;
	U32				tex_x;
	U32				tex_y;
	U32				color;
	U32				x;
	U32				y;
}					t_renderer;

typedef	struct		s_window
{
	SDL_Window		*window;
	SDL_Surface		*screen;
	U32				*screen_ptr;
	U32				height;
	U32				width;
}					t_window;

typedef	struct		s_texture
{
	IMAGE			*logo;
}					t_texture;

typedef struct		s_dnengine
{
	STRUCT_WINDOW	window;
	TEXTURE			texture;
	SDL_Event		event;
	RENDERER		renderer;
	bool			power;
	bool			pause;
	double			fps;
}					t_dnengine;

DN_ERROR			run_engine(ENGINE *doom);
DN_ERROR			stop_engine(ENGINE *doom);
DN_ERROR			parse_events(ENGINE *doom);
DN_ERROR			show_menu(ENGINE *doom);
DN_ERROR			run_game(ENGINE *doom);
void				draw_image(ENGINE *doom, IMAGE *image, U8 flag);
void				clear_window(ENGINE *doom);


#endif