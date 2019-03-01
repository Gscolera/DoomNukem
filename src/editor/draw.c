#include "editor.h"

static void		set_pixel(SDL_Surface *s, Uint16 x, Uint16 y, Uint32 color)
{
	Sint32	*ptr;

	ptr = (Sint32 *)s->pixels;
	if (x < s->w && x >= 0 && y < s->h && y >= 0)
		ptr[x + y * s->w] = color;
}

void	draw_point(EDITOR *editor, POINT_LIST *p, Uint32 color)
{
	Uint16	centerx;
	Uint16	centery;
	Sint16	radius;
	Sint16	x;
	Sint16	y;

	centerx = p->x * GRID_SIZE;
	centery = p->y * GRID_SIZE;
	// if (ACTIVE_POINT->x == p->x && ACTIVE_POINT->y == p->y)
	// 	radius = 10;
	// else
		radius = 7;
	if (ACTIVE_POINT->x == p->x && ACTIVE_POINT->y == p->y)
		color = 0x4f0468;
	x = -radius - 1;
	while (++x < radius)
	{
		y = -radius - 1;
		while (++y < radius)
		{
			if (x * x + y * y <= radius * radius)
				set_pixel(WS, centerx + x, centery + y, color);
		}
	}
}
// void	draw_point(EDITOR *editor, POINT_LIST *p, Uint32 color)
// {
// 	Uint16 	centerx;
// 	Uint16 	centery;
// 	Uint16	x;
// 	Uint16	y;
// 	Uint16	size;

// 	centerx = p->x * GRID_SIZE - WS_RECT.x;
// 	centery = p->y * GRID_SIZE - WS_RECT.y;
// 	if (ACTIVE_POINT && p->x == ACTIVE_POINT->x && p->y == ACTIVE_POINT->y)
// 		size = 8;
// 	else
// 		size = 6;
// 	if (centerx < 0 || centerx >= WS_WIDTH)
// 		return ;
// 	if (centery < 0 || centery >= WS_HEIGHT)
// 		return ;
// 	x = centerx - size;
// 	while (++x < centerx + size)
// 	{
// 		y = centery - size;
// 		while (++y < centery + size)
// 			set_pixel(WS, x, y, color);
// 	}
// }

void	draw_points(EDITOR *editor)
{
	SECTOR_LIST *sector;
	POINT_LIST	*point;
	Uint32		color;

	sector = SECTOR;
	while(sector)
	{
		point = sector->point;
		color = (sector->convex) ? 0x265603 : 0x5b0a01;
		while (point)
		{
			draw_point(editor, point, color);
			// if (point->next)
			// 	DrawLine(editor, point, point->next);
			point = point->next;
		}
		sector = sector->next;
	}
	SDL_UpdateWindowSurface(EDITOR_WINDOW);
}


