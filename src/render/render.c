/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:27:11 by cmelara-          #+#    #+#             */
/*   Updated: 2019/02/21 11:34:57 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

/*
** Clipping functionality:
** 1) If the edge behind the camera - skip it
** 2) If the edge partially behind the camera - clip it
*/
bool	clip(t_pipeline *render)
{
	t_point		rotated1;
	t_point		rotated2;
	t_point		i1;
	t_point		i2;
	t_frustum	cam;

	rotated1 = render->rotated.v1;
	rotated2 = render->rotated.v2;
	cam = render->cam;
	if (rotated1.y <= 0 && rotated2.y <= 0)
		return (false);
	else if (rotated1.y <= 0 || rotated2.y <= 0)
	{
		i1 = intersect(rotated1, rotated2, cam.near_left, cam.far_left);
		i2 = intersect(rotated1, rotated2, cam.near_right, cam.far_right);
		if (rotated1.y < cam.nearz)
		{
			render->rotated.v1.x = (i1.y > 0) ? i1.x : i2.x;
			render->rotated.v1.y = (i1.y > 0) ? i1.y : i2.y;
		}
		if (rotated2.y < cam.nearz)
		{
			render->rotated.v2.x = (i1.y > 0) ? i1.x : i2.x;
			render->rotated.v2.y = (i1.y > 0) ? i1.y : i2.y;
		}
	}
	return (true);
}

bool	is_edge_visible(t_rpiece current_portal, t_range tx)
{
	int	xmin;
	int	xmax;

	xmin = current_portal.xmin;
	xmax = current_portal.xmax;
	if (tx.x1 >= tx.x2 || tx.x2 < xmin || tx.x1 > xmax)
		return (false);
	return (true);
}

void	init_frame(ENGINE *doom, t_pipeline *render, t_queue *queue)
{
	t_rpiece	current;

	for (int x = 0; x < WINDOW_WIDTH; x++)
		doom->render.ytop[x] = 0;
	for (int x = 0; x < WINDOW_WIDTH; x++)
		doom->render.ybottom[x] = WINDOW_HEIGHT - 1;

	init_render_queue(queue);
	current.sector = doom->player.sector;
	current.xmin = 0;
	current.xmax = WINDOW_WIDTH - 1;
	*(queue->queue_head) = current;
	if (++(queue->queue_head) == queue->queue + MAX_PORTALS_PENDING)
		queue->queue_head = queue->queue;
}

void	project_floor_ceil(ENGINE *doom, t_pipeline *render)
{
	project_steps(doom, &(render->sstep1), &(render->sstep2), render->rstep);
	project_steps(doom, &(render->snstep1), &(render->snstep2), render->rnstep);
}

void	render_step_walls(ENGINE *doom, t_step step, int x, t_range tx)
{
	t_pipeline	*render;
	Uint32		wall_color;
	t_step		xnstep;
	t_step		nstep;

	render = &doom->render;
	wall_color = (x == tx.x1 || x == tx.x2) ? 0 : 0x010101 * 255;
	xnstep.floor = (x - tx.x1) * (render->snstep2.floor - render->snstep1.floor)
					/ (tx.x2 - tx.x1) + render->snstep1.floor;
	xnstep.ceil = (x - tx.x1) * (render->snstep2.ceil - render->snstep1.ceil)
					/ (tx.x2 - tx.x1) + render->snstep1.ceil;
	nstep.floor = clamp(xnstep.floor, render->ytop[x], render->ybottom[x]);
	nstep.ceil = clamp(xnstep.ceil, render->ytop[x], render->ybottom[x]);
	line(doom, x, step.ceil, nstep.ceil - 1, 0, 0, wall_color);
	render->ytop[x] = clamp(max(step.ceil, nstep.ceil), render->ytop[x], WINDOW_HEIGHT - 1);
	line(doom, x, nstep.floor + 1, step.floor, 0, 0, wall_color);
	render->ybottom[x] = clamp(min(step.floor, nstep.floor), 0, render->ybottom[x]);
}

void	render_wall(ENGINE *doom, int x, t_range tx)
{
	t_pipeline	*render;
	Uint32		wall_color;
	t_step		xstep;
	t_step		step;

	render = &doom->render;
	wall_color = (x == tx.x1 || x == tx.x2) ? 0 : 0x010101 * 255;
	xstep.floor = (x - tx.x1) * (render->sstep2.floor - render->sstep1.floor)
					/ (tx.x2 - tx.x1) + render->sstep1.floor;
	xstep.ceil = (x - tx.x1) * (render->sstep2.ceil - render->sstep1.ceil)
					/ (tx.x2 - tx.x1) + render->sstep1.ceil;
	step.floor = clamp(xstep.floor, render->ytop[x], render->ybottom[x]);
	step.ceil = clamp(xstep.ceil, render->ytop[x], render->ybottom[x]);
	line(doom, x, render->ytop[x], step.ceil - 1, 0, 0, 0x4A4845);
	line(doom, x, step.floor + 1, render->ybottom[x], 0, 0, 0x564635);
	if (render->neighbor >= 0)
		render_step_walls(doom, step, x, tx);
	else
		line(doom, x, step.ceil, step.floor, 0, 0, wall_color);

	// SDL_Delay(1);
	// update_screen(doom);
}

void	draw_geometry(ENGINE *doom)
{
	t_pipeline	*render;
	t_queue		queue;
	t_range		draw_range;

	render = &(doom->render);
	init_frame(doom, render, &queue);
	while (queue.queue_head != queue.queue_tail)
	{
		get_next_portal(doom, &queue);
		for (int v = 0; v < render->sector->npoints - 1; ++v)
		{
			translate(render, doom->player.position, v);
			rotate(render, doom->player.anglesin, doom->player.anglecos);
			if (!clip(render))
				continue ;
			project(doom, queue, &(render->tx), &(draw_range));
			if (!is_edge_visible(queue.current_portal, render->tx))
				continue ;
			translate_steps(doom);
			project_floor_ceil(doom, render);
			for (int x = draw_range.x1; x <= draw_range.x2; x++)
				render_wall(doom, x, render->tx);
			schedule_neighbor(render, &queue, draw_range);
		}
	}
}

void	render(ENGINE *doom)
{
	//clear_screen(doom, 0);
	draw_geometry(doom);
	draw_gun(doom);
	update_screen(doom);
}
