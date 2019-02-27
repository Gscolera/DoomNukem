#ifndef EDITOR_DEFINITIONS_H
# define EDITOR_DEFINITIONS_H

/*
*******************BASIC DEFINITIONS*******************************
*/
# define ED_WIN_WIDTH			1200
# define ED_WIN_HEIGHT			800
# define GRID_SIZE				40
# define WS_WIDTH				4000
# define WS_HEIGHT				4000
# define EDITOR					t_editor
/*
***************EDITOR STATE DEFINITIONS*****************************
*/
# define EDITOR_STATE			t_editor_state
# define ESTATE					editor->state
/*
****************EDITOR WINDOW DEFINITIONS**************************
*/
# define EDITOR_WINDOW_STRUCT	t_editor_window
# define EDITOR_WINDOW			editor->window.window
# define EDITOR_SCREEN			editor->window.screen
# define EDITOR_SPTR			editor->window.editor_ptr
# define EWW					editor->window.window_width
# define EWH					editor->window.window_height
/*
***************WORKING SURFACE DEFINITIONS****************************
*/
# define WORKING_SURFACE		t_working_surface
# define WS						editor->working_surface.ws
# define WS_PTR					editor->working_surface.ptr
# define WS_RECT				editor->working_surface.rect
# define WS_POS					editor->working_surface.pos
# define WS_UPDATED				editor->working_surface.updated
/*
*************POINTS DEFINITIONS*************************************
*/
# define POINT_LIST				t_point_list
# define SECTOR_LIST			t_sector_list
# define SECTOR					editor->sector_list
# define ACTIVE_SECTOR			editor->active_sector
# define ACTIVE_POINT			editor->active_point
# define UNIQUE_LIST			editor->unique
# define SECTOR_AMOUNT			editor->sector_amount
/*
*************BAR DEFINITIONS******************************************
*/
# define BAR_STRUCT				t_bar
# define BAR_OPTIONS			t_bar_options
# define BAR					editor->bar
# define BAR_COLOR				0x092826

#endif