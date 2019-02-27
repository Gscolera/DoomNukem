/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:37:52 by cmelara-          #+#    #+#             */
/*   Updated: 2019/02/20 19:58:10 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	translate(t_pipeline *render, t_position ppos, int v)
{
	render->local.v1 = render->sector->vertex[v];
	render->local.v2 = render->sector->vertex[v + 1];
	render->relative.v1.x = render->local.v1.x - ppos.x;
	render->relative.v1.y = render->local.v1.y - ppos.y;
	render->relative.v2.x = render->local.v2.x - ppos.x;
	render->relative.v2.y = render->local.v2.y - ppos.y;
	render->neighbor = render->sector->neighbors[v];
}

void	rotate(t_pipeline *render, float psin, float pcos)
{
	t_point	relative1;
	t_point	relative2;

	relative1 = render->relative.v1;
	relative2 = render->relative.v2;
	render->rotated.v1.x = relative1.x * psin - relative1.y * pcos;
	render->rotated.v1.y = relative1.x * pcos + relative1.y * psin;
	render->rotated.v2.x = relative2.x * psin - relative2.y * pcos;
	render->rotated.v2.y = relative2.x * pcos + relative2.y * psin;
}

int		project_x(ENGINE *doom, t_point rotated, t_point scaled)
{
	return (HALF_WIDTH - (int)(rotated.x * scaled.x));
}

void	project(ENGINE *doom, t_queue queue, t_range *tx, t_range *draw_range)
{
	t_pipeline *render;

	render = &(doom->render);
	render->scaled.v1.x = render->cam.hfov / render->rotated.v1.y;
	render->scaled.v1.y = render->cam.vfov / render->rotated.v1.y;
	render->scaled.v2.x = render->cam.hfov / render->rotated.v2.y;
	render->scaled.v2.y = render->cam.vfov / render->rotated.v2.y;
	tx->x1 = project_x(doom, render->rotated.v1, render->scaled.v1);
	tx->x2 = project_x(doom, render->rotated.v2, render->scaled.v2);
	draw_range->x1 = max(tx->x1, queue.current_portal.xmin);
	draw_range->x2 = min(tx->x2, queue.current_portal.xmax);
}
