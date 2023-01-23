/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 09:50:30 by elel-yak          #+#    #+#             */
/*   Updated: 2023/01/23 09:52:51 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_zoom(int botton, int x, int y, t_fractol *fractol)
{
	t_zoom	zoom;

	zoom.zoom = 2.0;
	if (botton == 4)
		zoom.zoom = 0.5;
	zoom.tmp0 = fractol->plan.x_max - fractol->plan.x_min;
	zoom.tmp1 = fractol->plan.y_max - fractol->plan.y_min;
	zoom.x_cord = (((x / 1000.0) * (fractol->plan.x_max - fractol->plan.x_min))
			+ fractol->plan.x_min);
	zoom.y_cord = ((-(y) / 1000.0) * (fractol->plan.y_max - fractol->plan.y_min)
			+ fractol->plan.y_max);
	fractol->plan.x_max = zoom.x_cord + ((fractol->plan.x_max - zoom.x_cord)
			* zoom.zoom);
	fractol->plan.x_min = fractol->plan.x_max - (zoom.tmp0 * zoom.zoom);
	fractol->plan.y_max = zoom.y_cord + ((fractol->plan.y_max - zoom.y_cord)
			* zoom.zoom);
	fractol->plan.y_min = fractol->plan.y_max - (zoom.tmp1 * zoom.zoom);
}
