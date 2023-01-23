/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 09:45:29 by elel-yak          #+#    #+#             */
/*   Updated: 2023/01/23 09:51:01 by elel-yak         ###   ########.fr       */
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
	if (botton == 123)
		fractol->plan.x_min -= 0.1;
	if (botton == 124)
		fractol->plan.x_min += 0.1;
	if (botton == 125)
		fractol->plan.y_min += 0.1;
	if (botton == 126)
		fractol->plan.y_min -= 0.1;
	if (botton == 69)
		fractol->plan.x_max += 0.1;
	if (botton == 78)
		fractol->plan.x_max -= 0.1;
	if (botton == 53)
		close_window(fractol);
	return (0);
}
