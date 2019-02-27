/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:28:43 by cmelara-          #+#    #+#             */
/*   Updated: 2019/02/20 12:56:17 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	init_render(ENGINE *doom)
{
	doom->camera.nearz = 1e-4f;
	doom->camera.farz = 5.0f;
	doom->camera.nearside = 1e-5f;
	doom->camera.farside = 20.0f;
	doom->camera.near_left.x = -doom->camera.nearside;
	doom->camera.near_left.y = doom->camera.nearz;
	doom->camera.far_left.x = -doom->camera.farside;
	doom->camera.far_left.y = doom->camera.farz;
	doom->camera.near_right.x = doom->camera.nearside;
	doom->camera.near_right.y = doom->camera.nearz;
	doom->camera.far_right.x = doom->camera.farside;
	doom->camera.far_right.y = doom->camera.farz;
	doom->camera.hfov = 0.73f * WINDOW_HEIGHT;
	doom->camera.vfov = 0.2f * WINDOW_HEIGHT;

	doom->render.cam = doom->camera;

	// Top & Bottom pixels clamping
	// TODO: Free it at the end
	// TODO: realloc on screen change
	doom->render.ytop = (int *)malloc(sizeof(int) * WINDOW_WIDTH);
	doom->render.ybottom = (int *)malloc(sizeof(int) * WINDOW_WIDTH);
}
