/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daharwoo <daharwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 22:21:45 by cmelara-          #+#    #+#             */
/*   Updated: 2019/02/21 11:44:59 by daharwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	build_sectors(ENGINE *engine)
{

	int		wall_width = 10;
	int		sectors = 100;

	engine->map.sectors = (t_sector *)malloc(sizeof(t_sector) * sectors);
	engine->map.nsectors = sectors;
	for (int i = 0; i < sectors; i++)
	{
		engine->map.sectors[i].floor = 0;
		engine->map.sectors[i].ceil = 30;
		engine->map.sectors[i].npoints = 5;
		engine->map.sectors[i].vertex = malloc(sizeof(t_point)
											* engine->map.sectors[i].npoints);
		{
			engine->map.sectors[i].vertex[0].x = wall_width * i;
			engine->map.sectors[i].vertex[0].y = 0;
			engine->map.sectors[i].vertex[1].x = wall_width * (i + 1);
			engine->map.sectors[i].vertex[1].y = 0;
			engine->map.sectors[i].vertex[2].x = wall_width * (i + 1);
			engine->map.sectors[i].vertex[2].y = wall_width;
			engine->map.sectors[i].vertex[3].x = wall_width * i;
			engine->map.sectors[i].vertex[3].y = wall_width;
			engine->map.sectors[i].vertex[4].x = wall_width * i;
			engine->map.sectors[i].vertex[4].y = 0;
		}
		engine->map.sectors[i].neighbors = malloc(sizeof(char)
										* engine->map.sectors[0].npoints - 1);
		engine->map.sectors[i].neighbors[0] = -1;
		engine->map.sectors[i].neighbors[1] = (i == sectors - 1) ? -1 : i + 1;
		engine->map.sectors[i].neighbors[2] = -1;
		engine->map.sectors[i].neighbors[3] = (i == 0) ? -1 : i - 1;
	}
}

void	player_init(ENGINE *engine)
{
	int i = 30;

	engine->player.position.x = 10 * i + 5;
	engine->player.position.y = 5;

	engine->player.velocity.x = 0;
	engine->player.velocity.y = 0;
	engine->player.velocity.z = 0;

	engine->player.angle = 0;
	engine->player.anglecos = sinf(0);
	engine->player.anglesin = cosf(0);
	engine->player.yaw = 0;

	engine->player.sector = i;

	engine->player.position.z = engine->map.sectors[engine->player.sector].floor + EYE_HEIGHT;
}

void	map_init(ENGINE *engine)
{
	build_sectors(engine);
	player_init(engine);
}
