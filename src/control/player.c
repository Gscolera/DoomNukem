/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daharwoo <daharwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:19:43 by cmelara-          #+#    #+#             */
/*   Updated: 2019/02/21 13:26:12 by daharwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	check_sector_cross(ENGINE *doom, float dx, float dy)
{
	t_sector	*sector;
	t_point		*vertex;
	float px;
	float py;

	sector = &doom->map.sectors[doom->player.sector];
	vertex = sector->vertex;
	px = doom->player.position.x;
	py = doom->player.position.y;
	for (int v = 0; v < sector->npoints; v++)
	{
		if (sector->neighbors[v] >= 0
			&& intersect_box((t_point) {px, py}, (t_point) {px + dx, py + dy},
							vertex[v], vertex[v + 1])
			&& point_side(px + dx, py + dy, vertex[v], vertex[v + 1]) < 0)
		{
			doom->player.sector = sector->neighbors[v];
			break ;
		}
	}
}

void	move_player(ENGINE *doom, float dx, float dy)
{
	float deltax;
	float deltay;
	float move_speed;

	move_speed = 100.0f;
	deltax = doom->delta_time * dx * move_speed;
	deltay = doom->delta_time * dy * move_speed;
	check_sector_cross(doom, deltax, deltay);
	doom->player.position.x += deltax;
	doom->player.position.y += deltay;
}
