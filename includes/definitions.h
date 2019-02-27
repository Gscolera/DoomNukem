#ifndef DEFINITIONS_H
# define DEFINITIONS_H

/*
**************BASIC DEFINITIONS******************************************
*/

# define START_WIDTH	1280
# define START_HEIGHT	720
# define FPS			60
# define SHOT			doom->shot
# define MOUSE          doom->mouse_control
# define HEALTH			doom->player.health
# define U32			unsigned int
# define U8				unsigned char

/*
**************STRUCTS DEFINITIONS*****************************************
*/

# define ENGINE			t_dnengine
# define STRUCT_WINDOW	t_window
# define TEXTURE		t_texture
# define DN_ERROR		t_error
# define RENDERER		t_renderer
# define GAME_MODE		t_gamemode

/*
**************WINDOW DEFINITIONS*****************************************
*/

# define WINDOW			doom->window.window
# define SCREEN			doom->window.screen
# define SCREEN_PTR		doom->window.screen_ptr
# define SURF_PIXELS	doom->window.screen->pixels
# define SCREEN_BYTES  	SCREEN->format->BytesPerPixel
# define WINDOW_WIDTH	doom->window.width
# define WINDOW_HEIGHT	doom->window.height

/*
**************TEXTURE DEFINITIONS*****************************************
*/
# define CROSS			doom->texture.cross

/*
**************EVENT DEFINITIONS*******************************************
*/

# define EVENT			doom->event
# define ETYPE			doom->event.type
# define KEY			doom->event.key.keysym.sym
# define BUTTON			doom->event.button.button
# define KEY_STATE		doom->keystate

/*
**************RENDERER DEFINITIONS******************************************
*/

# define X_OFFSET		doom->renderer.screen.x /*ОСТСТУП ПО ОСИ Х ЭКРАНА*/
# define Y_OFFSET		doom->renderer.screen.y /*ОТСТУП ПО ОСИ У ЭКРАНА*/
# define REND_SH		doom->renderer.screen.h /*ВЫСОТА УЧАСТКА ЭКРАНА НА КОТОРЫЙ ВЫВОДИМ ИЗОБРАЖЕНИЕ*/
# define REND_SW		doom->renderer.screen.w /*ШИРИНА УЧАСТКА ЭКРАНА НА КОТОРЫЙ ВЫВОДИМ ИЗОБРАЖЕНИЕ*/
# define XI_OFFSET		doom->renderer.image.x /*ОТСТУП ПО ОСИ Х ТЕКСТУРЫ*/
# define YI_OFFSET		doom->renderer.image.y /*ОТСТУП ПО ОСИ У ТЕКСТУРЫ*/
# define REND_IH		doom->renderer.image.h /*ВЫСОТА ВЫВОДИМОГО КУСКА ТЕКСТУРЫ*/
# define REND_IW		doom->renderer.image.w /*ШИРИНА ВЫВОДИМОГО КУСКА ТЕКСТУРЫ*/
# define TEXX			doom->renderer.tex_x /*СЛЕДУЮЩИЕ 4 ПОЛЯ ВАМ НЕ НУЖНЫ*/
# define TEXY			doom->renderer.tex_y
# define COLOR			doom->renderer.color
# define X				doom->renderer.x
# define Y				doom->renderer.y
# define SCREEN_RECT	0 /*ОПРЕДЕЛЕНЫ ТОЛЬКО ПАРАМЕТРЫ ЭКРАНА, ИЗОБРАЖЕНИЕ БУДЕТ ВЫВЕДЕНО ПОЛНОСТЬЮ*/
# define IMAGE_RECT		1 /*ОПРЕДЕЛЕНЫ ТОЛЬКО ПАРАМЕТРЫ ИЗОБРАЖЕНИЯ, БУДУТ ВЫВОДИТЬСЯ НА С ПЕРВОГО ПИСКЕЛЯ ЭКРАНА ПОСЛЕДОВАТЕЛЬНО*/
# define BOTH_RECTS		2 /*ОПРЕДЕЛЕНЫ ОБА ПАРАМЕТРА*/
# define NO_RECTS       3 /*ВПРИНЦИПЕ МОЖНО ПОДАВАТЬ И ЛЮБОЕ ДРУГОЕ ЧИСЛО, ОТЛИЧНОЕ ОТ ЗАДЕФАЙНЕННЫХ. ИЗОБРАЖЕНИЕ БУДЕТ РАСТЯНУТО НА ВЕСЬ ЭКРАН*/
#endif
