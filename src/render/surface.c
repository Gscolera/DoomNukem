/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 20:40:22 by cmelara-          #+#    #+#             */
/*   Updated: 2019/02/22 18:44:36 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	clear_screen(ENGINE *doom, Uint32 color)
{
	SDL_FillRect(SCREEN, NULL, color);
}

void	put_pixel(ENGINE *doom, int x, int y, Uint32 color)
{
	*(Uint32 *)(SURF_PIXELS + (x + y * WINDOW_WIDTH) * SCREEN_BYTES) = color;
}

void	safe_put_pixel(ENGINE *doom, int x, int y, Uint32 color)
{
	if (x < 0 || y < 0 || x > WINDOW_WIDTH - 1 || y > WINDOW_HEIGHT - 1)
		return ;
	*(Uint32 *)(SURF_PIXELS + (x + y * WINDOW_WIDTH) * SCREEN_BYTES) = color;
}

void	update_screen(ENGINE *doom)
{
	SDL_UpdateWindowSurface(WINDOW);
}
