/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 14:36:53 by cmelara-          #+#    #+#             */
/*   Updated: 2019/02/17 18:04:10 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

float	normalize(float x, float min, float max)
{
	return ((x - min) / (max - min));
}

float	min(float a, float b)
{
	return (a < b ? a : b);
}

float	max(float a, float b)
{
	return (a > b ? a : b);
}

float	clamp(float a, float mi, float ma)
{
	return (min(max(a, mi), ma));
}

bool	overlap(float a0, float a1, float b0, float b1)
{
	return (min(a0, a1) <= max(b0, b1) && min(b0, b1) <= max(a0, a1));
}
