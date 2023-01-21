/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 09:28:43 by elel-yak          #+#    #+#             */
/*   Updated: 2023/01/20 20:53:36 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

void	my_mlx_pixel_put(t_fractol *fractol, int x, int y, int color)
{
	char	*dst;

	dst = fractol->image->addr + (y * fractol->image->line_length + x
			*(fractol->image->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

int	in_mandelbrot(long double x, long double y)
{
	t_mandel mandel;

	mandel.re = 0;
	mandel.im = 0;
	mandel.re_factor = x;
	mandel.im_factor = y;
	mandel.iter = 0;
	while (((pow(mandel.re, 2)) + (pow(mandel.im, 2))) < 4 && mandel.iter < MAX_ITER)
	{
		mandel.tmp = pow(mandel.re, 2) - pow(mandel.im, 2) + mandel.re_factor;
		mandel.im = 2 * mandel.re * mandel.im + mandel.im_factor;
		mandel.re = mandel.tmp;
		mandel.iter++;
	}
	return (mandel.iter);
}

int	get_color(int i)
{
	const int	colors[20] = {0x000000, 0x000033, 0x000066, 0x000099, 0x0000cc,
	0x0000ff, 0x3300ff, 0x6600ff, 0x9900ff, 0xcc00ff,
	0xff00ff, 0xff00cc, 0xff0099, 0xff0066, 0xff0033,
	0xff0000, 0xff3300, 0xff6600, 0xff9900, 0xffff00};
	return colors[i];
}

int	render(t_fractol *fractol)
{
	t_render	render;

	render.a = 0;
	mlx_destroy_image(fractol->mlx, fractol->image->img);
	fractol->image->img = mlx_new_image(fractol->mlx, 1000, 1000);
	fractol->image->addr = mlx_get_data_addr(fractol->image->img,
			&fractol->image->bits_per_pixel, &fractol->image->line_length,
			&fractol->image->endian);
	while (render.a < 1000)
	{
		render.x = (((render.a / 1000.0) * (fractol->plan.x_max - fractol->plan.x_min)) + fractol->plan.x_min);
		render.b = 0;
		while (render.b < 1000)
		{
			render.y = (((-(render.b) / 1000.0) * (fractol->plan.y_max - fractol->plan.y_min)) + fractol->plan.y_max);
			render.i = in_mandelbrot(render.x, render.y);
			if (render.i < MAX_ITER)
				my_mlx_pixel_put(fractol, render.a, render.b, get_color(render.i % 20));
			else
				my_mlx_pixel_put(fractol, render.a, render.b, 0);
			render.b++;
		}
		render.a++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win,
		fractol->image->img, 0, 0);
	return (0);
}

void	init_cords(t_fractol *fractol)
{
	fractol->plan.x_min = -3.0;
	fractol->plan.x_max = 3.0;
	fractol->plan.y_min = -3.0;
	fractol->plan.y_max = 3.0;
}

void	ft_zoom(int botton, int x, int y, t_fractol *fractol)
{
	long double	x_cord;
	long double	y_cord;
	long double	zoom;
	long double tmp[2];

	zoom = 2.0;
	if (botton == 4)
		zoom = 0.5;
	tmp[0] = fractol->plan.x_max - fractol->plan.x_min;
	tmp[1] = fractol->plan.y_max - fractol->plan.y_min;
	x_cord = (((x / 1000.0) * (fractol->plan.x_max - fractol->plan.x_min)) + fractol->plan.x_min);
	y_cord = (((-(y) / 1000.0) * (fractol->plan.y_max - fractol->plan.y_min)) + fractol->plan.y_max);
	fractol->plan.x_max = x_cord + ((fractol->plan.x_max - x_cord) * zoom);
	fractol->plan.x_min = fractol->plan.x_max - (tmp[0] * zoom);
	fractol->plan.y_max = y_cord + ((fractol->plan.y_max - y_cord) * zoom);
	fractol->plan.y_min = fractol->plan.y_max - (tmp[1] * zoom);
}

int	mouse_press(int botton, int x, int y, t_fractol *fractol)
{
	// TODO: implement zooming for mandelbrot set
	if (botton == 4 || botton == 5)
		ft_zoom(botton, x, y, fractol);
	return (0);
}

int	botton_press(int botton, int x, int y, t_fractol *fractol)
{
	if (botton == 53)
		exit(0);
	(void)x;
	(void)y;
	(void)fractol;
	return (0);
}

int	main(void)
{
	t_fractol    *fractol;

	fractol = malloc(sizeof(t_fractol));
	fractol->image = malloc(sizeof(t_image));

	fractol->mlx = mlx_init();
	fractol->win = mlx_new_window(fractol->mlx, 1000, 1000, "Mandelbrot Set");
	fractol->image->img = mlx_new_image(fractol->mlx, 1000, 1000);
	fractol->image->addr = mlx_get_data_addr(fractol->image->img, &fractol->image->bits_per_pixel, &fractol->image->line_length,
								&fractol->image->endian);
	init_cords(fractol);
	mlx_hook(fractol->win, 4, 0, mouse_press, fractol);
	mlx_hook(fractol->win, 2, 0, botton_press, fractol);
	mlx_loop_hook(fractol->mlx, render, fractol);
	mlx_loop(fractol->mlx);
}
