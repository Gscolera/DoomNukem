#include "editor.h"

static void	print_surface_id(EDITOR *editor)
{
	SDL_Surface	*text;
	char		*buff;
	
	buff = ft_strcat("sd", "SECTOR ", ACTIVE_SECTOR->id);
	text = TTF_RenderText_Blended(BAR.font, buff, BAR.header_color);
	BAR.text_rect.x = 5;
	BAR.text_rect.y = 5;
	BAR.text_rect.w = text->w;
	BAR.text_rect.h = text->h;
	SDL_BlitSurface(text, NULL, BAR.bar, &BAR.text_rect);
	SDL_FreeSurface(text);
	free(buff);
	BAR.text_rect.y += BAR.text_rect.h;
}

static void	print_surface_params(EDITOR *editor)
{
	SDL_Surface	*text;
	char		*buff;

	buff = ft_strcat("sf", "floor: ", ACTIVE_SECTOR->floor);
	text = TTF_RenderText_Blended(BAR.font, buff, BAR.text_color);
	BAR.text_rect.w = text->w;
	BAR.text_rect.h = text->h;
	SDL_BlitSurface(text, NULL, BAR.bar, &BAR.text_rect);
	SDL_FreeSurface(text);
	free(buff);
	BAR.text_rect.y += BAR.text_rect.h;
	buff = ft_strcat("sf", "cieling: ", ACTIVE_SECTOR->ceiling);	
	text = TTF_RenderText_Blended(BAR.font, buff, BAR.text_color);
	BAR.text_rect.w = text->w;
	BAR.text_rect.h = text->h;
	SDL_BlitSurface(text, NULL, BAR.bar, &BAR.text_rect);
	SDL_FreeSurface(text);
	free(buff);
	BAR.text_rect.y += BAR.text_rect.h;
}

static void	print_points(EDITOR *editor)
{
	SDL_Surface	*text;
	POINT_LIST	*tmp;
	Sint8		*buff;

	buff = ft_strcat("sd", "Total points: ", ACTIVE_SECTOR->points_amount);
	text = TTF_RenderText_Blended(BAR.font, buff, BAR.text_color);
	BAR.text_rect.w = text->w;
	BAR.text_rect.h = text->h;
	SDL_BlitSurface(text, NULL, BAR.bar, &BAR.text_rect);
	SDL_FreeSurface(text);
	free(buff);
	BAR.text_rect.y += BAR.text_rect.h;
	tmp = ACTIVE_SECTOR->point;
	while (tmp)
	{
		buff = ft_strcat("sfsf", "Point: ", tmp->x, " ", tmp->y);
		text = TTF_RenderText_Blended(BAR.font, buff, BAR.text_color);
		BAR.text_rect.w = text->w;
		BAR.text_rect.h = text->h;
		SDL_BlitSurface(text, NULL, BAR.bar, &BAR.text_rect);
		SDL_FreeSurface(text);
		free(buff);
		BAR.text_rect.y += BAR.text_rect.h;
		tmp = tmp->next;
	}
}

void		print_active_surface(EDITOR *editor)
{
	print_surface_id(editor);
	print_surface_params(editor);
	print_points(editor);
}