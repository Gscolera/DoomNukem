#include "editor.h"

void	add_sector(EDITOR *editor)
{
	SECTOR_LIST *tmp;


	if (!(ACTIVE_SECTOR = (SECTOR_LIST *)malloc(sizeof(SECTOR_LIST))))
	{
		ESTATE = EDITOR_MEMORY_ERROR;
		return ;
	}
	ACTIVE_SECTOR->points_amount = 0;
	ACTIVE_SECTOR->floor = 0.0f;
	ACTIVE_SECTOR->ceiling = 25.0f;
	ACTIVE_SECTOR->convex = false;
	ACTIVE_SECTOR->point = NULL;
	ACTIVE_SECTOR->next = NULL;
	ACTIVE_SECTOR->id = ++SECTOR_AMOUNT;
	BAR.updated = false;
	if (!SECTOR)
		SECTOR = ACTIVE_SECTOR;
	else
	{
		tmp = SECTOR;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ACTIVE_SECTOR;
	}
}

void	print_sectors(EDITOR *editor)
{
	int i;

	i = 0;
	ACTIVE_SECTOR = SECTOR;
	while (ACTIVE_SECTOR)
	{
		ACTIVE_POINT = ACTIVE_SECTOR->point;
		while(ACTIVE_POINT)
		{
			printf("SECTOR %d x: %f y: %f\n",i ,ACTIVE_POINT->x, ACTIVE_POINT->y);
			ACTIVE_POINT = ACTIVE_POINT->next;
		}
		
		ACTIVE_SECTOR = ACTIVE_SECTOR->next;
	}
}
