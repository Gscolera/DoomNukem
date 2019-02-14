#ifndef MENU_H
# define MENU_H

# define MENU			t_menu
# define MENU_OPTIONS	t_menuoptions
# define MENU_IMG		menu->image
# define MENU_MV_SOUND	menu->move_sound
# define MENU_BGMUSIC	menu->bg
# define MENU_CH_SOUND	menu->choose_sound
# define MENU_BUTTON	menu->button
# define OPTIONS		menu->options

typedef	enum			e_menuoptions
{
	NEW_GAME,
	EXIT
}						t_menuoptions;

typedef	struct			s_menu
{
	IMAGE				*image;
	Mix_Chunk			*move_sound;
	Mix_Chunk			*choose_sound;
	Mix_Music			*bg;
	IMAGE				*button[2];
	MENU_OPTIONS		options;
}						t_menu;

#endif