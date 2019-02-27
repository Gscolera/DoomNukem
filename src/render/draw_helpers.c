/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:11:12 by cmelara-          #+#    #+#             */
/*   Updated: 2019/02/19 11:12:20 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	line(ENGINE *doom, int x, int y1, int y2, Uint32 t, Uint32 b, Uint32 m)
{
	int y;

	y1 = clamp(y1, 0, WINDOW_HEIGHT - 1);
	y2 = clamp(y2, 0, WINDOW_HEIGHT - 1);
	if (y1 == y2)
		put_pixel(doom, x, y1, m);
	else if (y2 > y1)
	{
		put_pixel(doom, x, y1, t);
		y = y1 + 1;
		while (y < y2)
		{
			put_pixel(doom, x, y, m);
			y++;
		}
		put_pixel(doom, x, y2, b);
	}
}
