/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 09:28:43 by elel-yak          #+#    #+#             */
/*   Updated: 2023/01/17 21:50:47 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

void	my_mlx_pixel_put(t_fractol *fractol, int x, int y, int color)
{
	char	*dst;

	dst = fractol->mlx->addr + (y * fractol->mlx->line_length + x * (fractol->mlx->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

long double	in_mandelbrot(long double x, long double y)
{
	long double zx, zy, c_x, c_y;
	long double iteration;
	long double max_iteration = 100;
	zx = 0;
	zy = 0;
	c_x = x;
	c_y = y;
	iteration = 0;
	while (zx*zx + zy*zy < 4 && iteration < max_iteration)
	{
		long double zx_temp = zx*zx - zy*zy + c_x;
		zy = 2*zx*zy + c_y;
		zx = zx_temp;
		iteration++;
	}
	if (iteration == max_iteration)
	return (1);
	else
	return (0);
}

int	render(t_fractol *fractol)
{
	long double x;
	long double y;
	int a;
	int b;

	a = 0;
	b = 0;
	mlx_destroy_image(fractol->mlx->mlx_ptr, fractol->mlx->img);
	fractol->mlx->img = mlx_new_image(fractol->mlx->mlx_ptr, 1920, 1920);
	fractol->mlx->addr = mlx_get_data_addr(fractol->mlx->img, &fractol->mlx->bits_per_pixel, &fractol->mlx->line_length,
											&fractol->mlx->endian);

	while (a < 1000)
	{
		x = (((a / 1000.0) * 6) - 3);
		while (b < 1000)
		{
			y = (((-b / 1000.0) * 6) + 3);
			if (in_mandelbrot(x, y))
				my_mlx_pixel_put(fractol, a, b, 0x00E4FA);
			b++;
		}
		a++;
	}

	mlx_put_image_to_window(fractol->mlx->mlx_ptr, fractol->mlx->win_ptr, fractol->mlx->img, 0, 0);
	return (0);
}

int	main(void)
{
 	t_fractol	*fractol;

	fractol = malloc(sizeof(t_fractol));
	fractol->mlx = malloc(sizeof(t_data));

 	fractol->mlx->mlx_ptr = mlx_init();
 	fractol->mlx->win_ptr = mlx_new_window(fractol->mlx->mlx_ptr, 1000, 1000, "Mandelbrot Set");
 	fractol->mlx->img = mlx_new_image(fractol->mlx->mlx_ptr, 1000, 1000);
 	fractol->mlx->addr = mlx_get_data_addr(fractol->mlx->img, &fractol->mlx->bits_per_pixel, &fractol->mlx->line_length,
 								&fractol->mlx->endian);

	mlx_loop_hook(fractol->mlx->mlx_ptr, render, fractol);
 	mlx_loop(fractol->mlx->mlx_ptr);
}
