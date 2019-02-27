/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anton <anton@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 11:36:23 by cmelara-          #+#    #+#             */
/*   Updated: 2019/02/28 02:32:34 by anton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_H
# define EDITOR_H

# ifdef __linux__
#  include <SDL2/SDL.h>
#  include <SDL2/SDL_mixer.h>
#  include <SDL2/SDL_ttf.h>
# else
#  include "SDL.h"
#  include "SDL_mixer.h"
#  include "SDL_ttf.h"
# endif

# include "editor_definitions.h"
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <stdarg.h>

typedef	enum				s_editor_state
{
	EDITOR_RUNNING,
	EDITOR_MEMORY_ERROR,
	EDITOR_SDL_ERROR,
	EDITOR_EXIT_SUCCESS
}							t_editor_state;

typedef	enum				s_bar_options
{
	SECTOR_MODE,
	SAVE_MODE
}							t_bar_options;

typedef	struct				s_point_list
{
	double					x;
	double					y;
	struct s_point_list		*next;
}							t_point_list;

typedef	struct 				s_sector_list
{
	POINT_LIST				*point;
	SDL_Surface				*name;
	Uint16					points_amount;
	Uint16					id;
	double					floor;
	double					ceiling;
	bool					convex;
	struct s_sector_list	*next;
}							t_sector_list;

typedef	struct				s_working_surface
{
	SDL_Surface				*ws;
	Uint32					*ptr;
	SDL_Rect				rect;
	SDL_Rect				pos;
	bool					updated;
}							t_working_surface;

typedef	struct				s_editor_window
{
	SDL_Window				*window;
	SDL_Surface				*screen;
	Uint32					*editor_ptr;
	Uint16					window_height;
	Uint16					window_width;
}							t_editor_window;

typedef	struct				s_bar
{
	SDL_Surface				*bar;
	TTF_Font				*font;
	SDL_Surface				*text;
	SDL_Color				text_color;
	SDL_Color				header_color;
	SDL_Rect				rect;
	SDL_Rect				text_rect;
	BAR_OPTIONS				mode;
	bool					activated;
	bool					updated;
}							t_bar;

typedef struct				s_editor
{
	EDITOR_WINDOW_STRUCT	window;
	WORKING_SURFACE			working_surface;
	SECTOR_LIST				*sector_list;
	Uint16					sector_amount;
	SECTOR_LIST				*active_sector;
	POINT_LIST				*active_point;
	POINT_LIST				*unique;
	EDITOR_STATE			state;
	BAR_STRUCT				bar;
}							t_editor;

EDITOR_STATE				run_editor();

/*
********************WORKING SURFACE******************************************
*/
void						init_working_surface(EDITOR *editor);
void						draw_working_surface(SDL_Surface *working_surface);
void						update_working_surface(EDITOR *editor);
/*
*******************BAR********************************************************
*/
void						init_bar(EDITOR *editor);
void						clear_surface(SDL_Surface *surface, Uint32 color);
void						activate_bar(EDITOR *editor);
void						print_active_surface(EDITOR *editor);
void						update_bar(EDITOR *editor);


POINT_LIST					*point_nearby(EDITOR *editor, SECTOR_LIST *sector);
void						init_editor(EDITOR *editor);
void						editor_parse_events(EDITOR *editor);
void						render_editor(EDITOR *editor);
void						destroy_editor(EDITOR *editor);
void						add_point(EDITOR *editor);
void						add_sector(EDITOR *editor);
void						print_sectors(EDITOR *editor);
void						draw_points(EDITOR *editor);
void						show_bar(EDITOR *editor);
void						draw_sector_list(EDITOR *editor);

/*
******************EDITOR HELPERS*********************************************
*/
void						ft_memset(Sint8 *ptr, Sint8 c, Uint32 size);
void						editor_itoa(Sint32 num, Sint8 *buff);
void						editor_dtoa(double num, Sint8 *buff, Sint8 prec);
Sint8						*ft_strcat(Sint8 *format, ...);

#endif
