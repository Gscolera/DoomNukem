/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:23:20 by cmelara-          #+#    #+#             */
/*   Updated: 2019/02/20 19:51:20 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	translate_portal_step(ENGINE *doom)
{
	t_pipeline	*render;
	int			neighbor;
	float		pz;

	render = &(doom->render);
	render->rnstep.floor = 0;
	render->rnstep.ceil = 0;
	pz = doom->player.position.z;
	neighbor = render->neighbor;
	if (render->neighbor >= 0)
	{
		render->rnstep.floor = doom->map.sectors[neighbor].floor - pz;
		render->rnstep.ceil = doom->map.sectors[neighbor].ceil - pz;
	}
}

void	translate_steps(ENGINE *doom)
{
	t_pipeline	*render;

	render = &(doom->render);
	render->rstep.floor = render->sector->floor - doom->player.position.z;
	render->rstep.ceil = render->sector->ceil - doom->player.position.z;
	translate_portal_step(doom);
}

float	project_step(int origin, float yaw, float sy)
{
	return (origin - (int)(yaw * sy));
}

void	project_steps(ENGINE *doom, t_step *step1, t_step *step2, t_fstep rstep)
{
	t_pipeline	*render;
	t_point		rot1;
	t_point		rot2;
	float		sy1;
	float		sy2;

	render = &(doom->render);
	rot1 = render->rotated.v1;
	rot2 = render->rotated.v2;
	sy1 = render->scaled.v1.y;
	sy2 = render->scaled.v2.y;
	step1->floor = project_step(HALF_HEIGHT, YAW(rstep.floor, rot1.y), sy1);
	step1->ceil = project_step(HALF_HEIGHT, YAW(rstep.ceil, rot1.y), sy1);
	step2->floor = project_step(HALF_HEIGHT, YAW(rstep.floor, rot2.y), sy2);
	step2->ceil = project_step(HALF_HEIGHT, YAW(rstep.ceil, rot2.y), sy2);
}
