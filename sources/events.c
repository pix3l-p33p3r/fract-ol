/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallaoui <mallaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 09:45:29 by elel-yak          #+#    #+#             */
/*   Updated: 2023/01/26 01:47:08 by mallaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mouse_press(int botton, int x, int y, t_fractol *fractol)
{
	if (botton == 4 || botton == 5)
		ft_zoom(botton, x, y, fractol);
	return (0);
}

int	close_window(t_fractol *fractol)
{
	mlx_destroy_window(fractol->mlx, fractol->win);
	exit(0);
	return (0);
}

int	botton_press(int botton, t_fractol *fractol)
{
	long double	g;

	g = ((fractol->plan.x_max - fractol->plan.x_min) / 10.0)
		* (-2.0 * (botton == 123 || botton == 125) + 1.0);
	if (botton == 15)
		fractol->color = 256 * 256 * 265;
	if (botton == 11)
		fractol->color = 265;
	if (botton == 5)
		fractol->color = 2 * 259 * 256;
	if (botton == 123 || botton == 124)
	{
		fractol->plan.x_min += g;
		fractol->plan.x_max += g;
	}
	else if (botton == 125 || botton == 126)
	{
		fractol->plan.y_min += g;
		fractol->plan.y_max += g;
	}
	if (botton == 53)
		close_window(fractol);
	return (0);
}
