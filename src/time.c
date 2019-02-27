/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:07:27 by cmelara-          #+#    #+#             */
/*   Updated: 2019/02/19 11:09:05 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	count_delta_time(ENGINE *doom)
{
	doom->last_time = doom->current_time;
	doom->current_time = SDL_GetPerformanceCounter();
	doom->delta_time = (double)((doom->current_time - doom->last_time)
								/ (double)SDL_GetPerformanceFrequency());
}
