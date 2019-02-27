#include "editor.h"

static void	free_points(POINT_LIST *point)
{
	POINT_LIST *tmp;

	while (point)
	{
		tmp = point->next;
		free(point);
		point = tmp;
	}
}

static void	free_sectors(EDITOR *editor)
{
	while (SECTOR)
	{
		ACTIVE_SECTOR = SECTOR->next;
		free_points(SECTOR->point);
		free(SECTOR);
		SECTOR = ACTIVE_SECTOR;
	}
}

void	destroy_editor(EDITOR *editor)
{
	free_sectors(editor);
	//free_points(UNIQUE_LIST);
	SDL_FreeSurface(WS);
	SDL_FreeSurface(BAR.bar);
	SDL_SetRelativeMouseMode(SDL_ENABLE);	
	SDL_ShowCursor(SDL_FALSE);
	//TTF_CloseFont(BAR_FONT);
	SDL_DestroyWindow(EDITOR_WINDOW);
}