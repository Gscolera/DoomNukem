/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_queue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:32:11 by cmelara-          #+#    #+#             */
/*   Updated: 2019/02/20 19:37:31 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	init_render_queue(t_queue *queue)
{
	queue->queue_head = queue->queue;
	queue->queue_tail = queue->queue;
}

void	get_next_portal(ENGINE *doom, t_queue *queue)
{
	queue->current_portal = *(queue->queue_tail);
	if (++(queue->queue_tail) == queue->queue + MAX_PORTALS_PENDING)
		queue->queue_tail = queue->queue;
	doom->render.sector = &doom->map.sectors[queue->current_portal.sector];
}

void	schedule_neighbor(t_pipeline *render, t_queue *queue, t_range draw_range)
{
	t_rpiece	*queue_head;
	t_rpiece	*queue_tail;
	t_rpiece	neighbor;
	int			max;
	int			is;

	max = MAX_PORTALS_PENDING;
	is = (queue->queue_head + max + 1 - queue->queue_tail) % max;
	if (render->neighbor >= 0 && draw_range.x1 <= draw_range.x2 && is)
	{
		neighbor.sector = render->neighbor;
		neighbor.xmin = draw_range.x1;
		neighbor.xmax = draw_range.x2;
		*(queue->queue_head) = neighbor;
		if (++(queue->queue_head) == queue->queue + max)
			queue->queue_head = queue->queue;
	}
}
