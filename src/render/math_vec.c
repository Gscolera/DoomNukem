/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_vec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 17:41:56 by cmelara-          #+#    #+#             */
/*   Updated: 2019/02/17 18:32:55 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

float	cross(t_point p0, t_point p1)
{
	return (p0.x * p1.y - p1.x * p0.y);
}

float	cross_scal(float x0, float x1, float y0, float y1)
{
	return (x0 * y1 - x1 * y0);
}

bool	intersect_box(t_point p0, t_point p1, t_point p2, t_point p3)
{
	return (overlap(p0.x, p1.x, p2.x, p3.x) && overlap(p0.y, p1.y, p2.y, p3.y));
}

t_point	vec_sub(t_point p0, t_point p1)
{
	t_point s;

	s.x = p0.x - p1.x;
	s.y = p0.y - p1.y;
	return (s);
}

t_point	scal_vec_sub(float x, float y, t_point p)
{
	t_point	s;

	s.x = x - p.x;
	s.y = y - p.y;
	return (s);
}

float	point_side(float px, float py, t_point p0, t_point p1)
{
	return (cross(vec_sub(p1, p0), scal_vec_sub(px, py, p0)));
}

t_point	intersect(t_point p0, t_point p1, t_point p2, t_point p3)
{
	t_point	i;
	float temp;

	temp = cross(vec_sub(p0, p1), vec_sub(p2, p3));
	i.x = cross_scal(cross(p0, p1), p0.x - p1.x, cross(p2, p3), p2.x - p3.x)
		/ temp;
	i.y = cross_scal(cross(p0, p1), p0.y - p1.y, cross(p2, p3), p2.y - p3.y)
		/ temp;
	return (i);
}
