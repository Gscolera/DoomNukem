/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anton <anton@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 20:10:32 by cmelara-          #+#    #+#             */
/*   Updated: 2019/02/22 14:08:15 by anton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	show_mouse(ENGINE *doom)
{
	if (!MOUSE)
	{
		SDL_ShowCursor(SDL_ENABLE);
		SDL_SetRelativeMouseMode(SDL_FALSE);
		MOUSE = true;
	}
}

void	hide_mouse(ENGINE *doom)
{
	if (MOUSE)
	{
		SDL_ShowCursor(SDL_DISABLE);
		SDL_SetRelativeMouseMode(SDL_TRUE);
		MOUSE = false;
	}
}

void	mouse_control(ENGINE *doom)
{
	static float yaw = 0;
	int	x;
	int	y;

	SDL_GetRelativeMouseState(&x, &y);
	doom->player.angle += x * 0.003f;

	yaw = clamp(yaw + y * 0.01f, -5, 5);
    doom->player.yaw = yaw - doom->player.velocity.z * 0.5f;

	doom->player.anglecos = cosf(doom->player.angle);
	doom->player.anglesin = sinf(doom->player.angle);
}
