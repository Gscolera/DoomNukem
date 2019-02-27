#include "editor.h"

static bool	get_point_params(EDITOR *editor)
{
	int x;
	int y;

	SDL_GetMouseState(&x, &y);
	x += (BAR.activated) ? WS_RECT.x - BAR.bar->w : WS_RECT.x;
	if (x < 0)
		return (0);
	y += WS_RECT.y;
	if (!(ACTIVE_POINT = (POINT_LIST *)malloc(sizeof(POINT_LIST))))
		exit(EDITOR_MEMORY_ERROR);
	if (!ACTIVE_SECTOR)
		add_sector(editor);
	ACTIVE_POINT->x = (double)x / GRID_SIZE;
	ACTIVE_POINT->y = (double)y / GRID_SIZE;
	ACTIVE_POINT->next = NULL;
	ACTIVE_SECTOR->points_amount++;
	return (1);
}

static void	add_unique_point(EDITOR *editor)
{
	POINT_LIST	*tmp;

	
	if (!UNIQUE_LIST)
		UNIQUE_LIST = ACTIVE_POINT;
	else
	{
		tmp = UNIQUE_LIST;
		while (tmp->next)
		{
			if (tmp->x == ACTIVE_POINT->x && tmp->y == ACTIVE_POINT->y)
				return ;
			tmp = tmp->next;
		}
		tmp->next = ACTIVE_POINT;
	}
}

static void	set_point_to_sector(EDITOR *editor)
{
	POINT_LIST *tmp;

	if (ACTIVE_SECTOR->point == NULL)
		ACTIVE_SECTOR->point = ACTIVE_POINT;
	else
	{	
		tmp = ACTIVE_SECTOR->point;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ACTIVE_POINT;
	}
}

void	add_point(EDITOR *editor)
{
	POINT_LIST	*closing_point;

	closing_point = NULL;
	if (!get_point_params(editor))
		return ;
	
	//add_unique_point(editor);
	// if (ACTIVE_SECTOR->points_amount > 3)
	// {
	// 	closing_point = point_nearby(editor, ACTIVE_SECTOR);
	// }
	// if (closing_point)
	// {

	// 	// ACTIVE_POINT->x = closing_point->x;
	// 	// ACTIVE_POINT->x = closing_point->y;
	// }
	set_point_to_sector(editor);
	BAR.updated = false;
	WS_UPDATED = false;
}