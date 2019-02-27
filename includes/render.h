/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anton <anton@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 21:52:12 by cmelara-          #+#    #+#             */
/*   Updated: 2019/02/22 18:30:52 by anton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# define EYE_HEIGHT		10
# define CROUCH_HEIGHT	2.5
# define HEAD_MARGIN	1
# define KNEE_HEIGHT	2
# define HFOV			(0.73f * WINDOW_HEIGHT)
# define VFOV			(0.2f * WINDOW_HEIGHT)
# define HALF_WIDTH		WINDOW_WIDTH / 2
# define HALF_HEIGHT	WINDOW_HEIGHT / 2
# define MAX_PORTALS_PENDING 32

# define YAW(y, z) (y + z * doom->player.yaw)

typedef struct  s_point
{
    float       x;
    float       y;
}               t_point;

typedef struct	s_fstep
{
	float		ceil;
	float		floor;
}				t_fstep;

typedef struct	s_step
{
	int			ceil;
	int			floor;
}				t_step;

typedef struct	s_edge
{
	t_point		v1;
	t_point		v2;
}				t_edge;

typedef struct	s_range
{
	int			x1;
	int			x2;
}				t_range;

typedef struct	s_position
{
	float		x;
	float		y;
	float		z;
}				t_position;

typedef struct  s_sector
{
    float       floor;
    float       ceil;
    t_point     *vertex;
	char		*neighbors;
	unsigned	npoints;
}               t_sector;

typedef struct	s_player
{
	t_position	position;
	t_position	velocity;
	U8			health;
	float		angle;
	float		anglesin;
	float		anglecos;
	float		yaw;
	unsigned	sector;
}				t_player;

typedef struct	s_frustum
{
	float		nearside;
	float		nearz;
	float		farside;
	float		farz;
	t_point		near_left;
	t_point		far_left;
	t_point		near_right;
	t_point		far_right;
	float		hfov;
	float		vfov;
}				t_frustum;

/*
********** Structure for sector rendering *********
*/

typedef struct	s_rpiece
{
	int			sector;
	int			xmin;
	int			xmax;
}				t_rpiece;

/*
*********** Render Pipeline **********
*/

typedef struct	s_queue
{
	t_rpiece	queue[MAX_PORTALS_PENDING];
	t_rpiece	*queue_head; // HEAD is for filling up
	t_rpiece	*queue_tail; // TAIL is for slicing and drawing
	t_rpiece	current_portal;
}				t_queue;

typedef struct	s_pipeline
{
	t_sector	*sector;
	int			*ytop;
	int			*ybottom;
	// Edge: Transform, Rotate, Scale, Edge's projected x points
	t_edge		local;
	t_edge		relative;
	t_edge		rotated;
	t_edge		scaled;
	t_range		tx;
	// rsstep = relative step (floor & ceil)
	// rsstep = relative neighbor's step (floor & ceil)
	t_fstep		rstep;
	t_fstep		rnstep;
	// sstep = screen-space step (floor & ceil)
	// snstep = Neighbor's screen-space step (floor & ceil)
	t_step		sstep1;
	t_step		sstep2;
	t_step		snstep1;
	t_step		snstep2;
	// View frustum
	t_frustum	cam;
	// Neighbor sector number
	int			neighbor;
}				t_pipeline;

/*
********* Math functions ***********
*/

float	normalize(float x, float min, float max);
float	min(float a, float b);
float	max(float a, float b);
float	clamp(float a, float mi, float ma);
bool	overlap(float a0, float a1, float b0, float b1);
float	cross(t_point p0, t_point p1);
float	cross_scal(float x0, float x1, float y0, float y1);
bool	intersect_box(t_point p0, t_point p1, t_point p2, t_point p3);
float	point_side(float px, float py, t_point p0, t_point p1);
t_point	intersect(t_point p0, t_point p1, t_point p2, t_point p3);

#endif
