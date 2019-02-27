#ifndef DOOM_NUKEM_H
# define DOOM_NUKEM_H

# ifdef __linux__
#  include <SDL2/SDL.h>
#  include <SDL2/SDL_mixer.h>
#  include <SDL2/SDL_ttf.h>
# else
#  include "SDL.h"
#  include "SDL_mixer.h"
#  include "SDL_ttf.h"
# endif

# include <math.h>
# include "definitions.h"
# include "tga_reader.h"
# include "menu.h"
# include "render.h"
# include "editor.h"
# include "gun.h"
# include "npc.h"

/*
******** RETURN TYPES ********
*/

typedef enum		e_error
{
	OK,
	MEMORY_ERROR,
	IMAGE_ERROR,
	SDL_ERROR,
	SOUND_ERROR,
	MENU_ERROR,
	EDITOR_ERROR
}					t_error;

typedef	enum		e_gamemode
{
	MAIN_MENU,
	GAME,
	PAUSE,
	MAP_EDITOR,
	QUIT
}					t_gamemode;

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

typedef struct		s_map
{
	t_sector		*sectors;
	unsigned		nsectors;
}					t_map;

typedef	struct		s_texture
{
	IMAGE			*cross;
}					t_texture;

typedef struct		s_dnengine
{
	STRUCT_WINDOW	window;
	TEXTURE			texture;
	SDL_Event		event;
	const Uint8		*keystate;
	RENDERER		renderer;
	GAME_MODE		mode;
	STRUCT_GUN		gun;
	bool			shot;
	bool 			mouse_control;
	double			fps;

	t_map			map;
	t_player		player;
	t_frustum		camera;
	t_pipeline		render;
	Uint64			current_time;
	Uint64			last_time;
	double			delta_time;
}					t_dnengine;

DN_ERROR			run_engine(ENGINE *doom);
DN_ERROR			stop_engine(ENGINE *doom);
DN_ERROR			parse_events(ENGINE *doom);
DN_ERROR			show_main_menu(ENGINE *doom);
DN_ERROR			show_pause_menu(ENGINE *doom);
DN_ERROR			show_editor(ENGINE *doom);
DN_ERROR			select_game_mode(ENGINE *doom);
IMAGE				*take_screenshot(ENGINE *doom);
void				draw_image(ENGINE *doom, IMAGE *image, U8 flag);
void				clear_window(ENGINE *doom);
void				render_menu(ENGINE *doom, MENU *menu);
void				render_pause_menu(ENGINE *doom, P_MENU *menu);
void				darken_image(IMAGE *image);

void				load_gun_textures(ENGINE *doom);
void				draw_gun(ENGINE *doom);
void				make_shot(ENGINE *doom);

/*
****************MOUSE************************************
*/
void				show_mouse(ENGINE *doom);
void				hide_mouse(ENGINE *doom);

/*
************ MAP FUNCTIONALITY ***********
*/

void				map_init(ENGINE *engine);


/*
************ RENDER ****************
*/

void				update_screen(ENGINE *doom);
void				clear_screen(ENGINE *doom, Uint32 color);
void				put_pixel(ENGINE *doom, int x, int y, Uint32 color);
void				safe_put_pixel(ENGINE *doom, int x, int y, Uint32 color);

void				init_render(ENGINE *doom);
void				render(ENGINE *doom);

/*
************ Render Pipeline functions ***************
*/

void	translate(t_pipeline *render, t_position ppos, int v);
void	rotate(t_pipeline *render, float psin, float pcos);
void	init_render_queue(t_queue *queue);
void	schedule_neighbor(t_pipeline *render, t_queue *queue, t_range draw_range);
void	get_next_portal(ENGINE *doom, t_queue *queue);
void	translate_steps(ENGINE *doom);
void	project_steps(ENGINE *doom, t_step *s1, t_step *s2, t_fstep rstep);
int		project_x(ENGINE *doom, t_point rotated, t_point scaled);
void	project(ENGINE *doom, t_queue queue, t_range *tx, t_range *draw_range);

/*
********* DRAW FUNCTIONS *************
*/

// DEBUG FUNCTION! DON'T TOUCH IT YET!
void	line(ENGINE *doom, int x, int y1, int y2, Uint32 t, Uint32 b, Uint32 m);

/*
************* PLAYER & PHYSICS ***********
*/

void	count_delta_time(ENGINE *doom);
void	move_player(ENGINE *doom, float dx, float dy);
void	mouse_control(ENGINE *doom);

/*
****************************** MAP EDITOR *******************************
*/

#endif
