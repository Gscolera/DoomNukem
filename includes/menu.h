#ifndef MENU_H
# define MENU_H

# define MENU				t_menu
# define MENU_OPTIONS		t_menuoptions
# define P_MENU				t_pausemenu
# define P_MENU_OPTIONS		t_pauseoptions
# define MENU_IMG			menu->background
# define MENU_MV_SOUND		menu->move_sound
# define MENU_BGMUSIC		menu->bg
# define MENU_CH_SOUND		menu->choose_sound
# define MENU_BUTTON		menu->button
# define MENU_FONT			menu->font
# define MENU_FCOLOR		menu->font_color
# define MENU_FONT_SIZE		menu->font_size
# define OPTIONS			menu->options
# define MENU_ACTIVE		1
# define MENU_NACTIVE		2



typedef	enum			e_menuoptions
{
	NEW_GAME,
	SAVE_GAME,
	LOAD_GAME,
	LEVEL_EDITOR,
	EXIT
}						t_menuoptions;

typedef	enum			s_pauseoptions
{
	RESUME_GAME,
	P_SAVE_GAME,
	P_LOAD_GAME,
	TO_MAIN_MENU
}						t_pauseoptions;

typedef	struct			s_menu
{
	IMAGE				*background;
	Mix_Chunk			*move_sound;
	Mix_Chunk			*choose_sound;
	Mix_Music			*bg;
	SDL_Surface			*button[5];
	SDL_Color			font_color;
	U8					font_size;
	TTF_Font			*font;
	MENU_OPTIONS		options;
}						t_menu;

typedef	struct			s_pausemenu
{
	IMAGE				*background;
	Mix_Chunk			*move_sound;
	Mix_Chunk			*choose_sound;
	Mix_Music			*bg;
	SDL_Surface			*button[4];
	SDL_Color			font_color;
	U8					font_size;
	TTF_Font			*font;
	P_MENU_OPTIONS		options;
}						t_pausemenu;

#endif