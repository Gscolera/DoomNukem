#ifndef DEFINITIONS_H
# define DEFIINITION_S
/*
**************BASIC DEFINITIONS******************************************
*/
# define START_WIDTH	1200
# define START_HEIGHT	800
# define FPS			60
# define POWER			doom->power
# define PAUSE			doom->pause
/*
**************STRUCTS DEFINITIONS*****************************************
*/
# define ENGINE			t_dnengine
# define STRUCT_WINDOW	t_window
# define TEXTURE		t_texture
# define DN_ERROR		t_error
# define RENDERER		t_renderer
/*
**************WINDOW DEFINITIONS*****************************************
*/
# define WINDOW			doom->window.window
# define SCREEN			doom->window.screen
# define SCREEN_PTR		doom->window.screen_ptr
# define WINDOW_WIDTH	doom->window.width
# define WINDOW_HEIGHT	doom->window.height
/*
**************TEXTURE DEFINITIONS*****************************************
*/
# define LOGO			doom->texture.logo
/*
**************EVENT DEFINITIONS*******************************************
*/
# define EVENT			doom->event
# define ETYPE			doom->event.type
# define KEY			doom->event.key.keysym.sym
/*
**************RENDERER DEFINITIONS******************************************
*/
# define X_OFFSET		doom->renderer.screen.x
# define Y_OFFSET		doom->renderer.screen.y
# define REND_SH		doom->renderer.screen.h
# define REND_SW		doom->renderer.screen.w
# define XI_OFFSET		doom->renderer.image.x
# define YI_OFFSET		doom->renderer.image.y
# define REND_IH		doom->renderer.image.h
# define REND_IW		doom->renderer.image.w
# define TEXX			doom->renderer.tex_x
# define TEXY			doom->renderer.tex_y
# define COLOR			doom->renderer.color
# define X				doom->renderer.x
# define Y				doom->renderer.y
# define SCREEN_RECT	0
# define IMAGE_RECT		1
# define BOTH_RECTS		2
#endif