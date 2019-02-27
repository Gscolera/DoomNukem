#include "editor.h"

// POINT_LIST	*point_nearby(EDITOR *editor, SECTOR_LIST *sector)
// {
// 	POINT_LIST	*tmp;
// 	POINT_LIST	new;
// 	int			x;
// 	int			y;
// 	int i;

// 	if (!sector)
// 		return (NULL);
// 	SDL_GetMouseState(&x, &y);
// 	new.x = (double)(x + WS_XOFFSET) / GRID_SIZE;
// 	new.y = (double)(y + WS_YOFFSET) / GRID_SIZE;
// 	tmp = sector->point;
// 	i = 1;
// 	while (tmp)
// 	{
// 		if (fabs(tmp->x - new.x) < 0.3 && fabs(tmp->y - new.y) < 0.3)
// 		{
// 			printf("%d %f %f\n", i, tmp->x, new.x);
// 			return(tmp);
// 		}
// 		tmp = tmp->next;
// 	}
// 	return (NULL);
// }