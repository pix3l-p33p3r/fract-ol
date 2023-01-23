/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 09:28:43 by elel-yak          #+#    #+#             */
/*   Updated: 2023/01/23 09:26:40 by elel-yak         ###   ########.fr       */
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

int	mandelbrot(long double x, long double y)
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

int	julia(long double x, long double y)
{
	t_julia julia;

	julia.re_factor = x;
	julia.im_factor = y;
	julia.iter = 0;
	while (((pow(julia.re_factor, 2)) + (pow(julia.im_factor, 2))) < 4 && julia.iter < MAX_ITER)
	{
		julia.tmp = pow(julia.re_factor, 2) - pow(julia.im_factor, 2) + 0.0;
		julia.im_factor = 2 * julia.re_factor * julia.im_factor - 0.8;
		julia.re_factor = julia.tmp;
		julia.iter++;
	}
	return (julia.iter);
}

int	get_color(int i) {
	const int colors[45] = {
	0x000020, 0x000040, 0x000060, 0x000080, 0x0000A0,
	0x0000C0, 0x0000E0, 0x0000FF, 0x1A1AFF, 0x3F3FFF,
	0x5F5FFF, 0x8F8FFF, 0xAFAFFF, 0xCFCFFF, 0xEFEFFF,
	0xFFFFFF, 0xFFEFEF, 0xFFCFCF, 0xFFAFAF, 0xFF8F8F,
	0xFF6F6F, 0xFF3F3F, 0xFF1A1A, 0xFF0000, 0xE50000,
	0xCC0000, 0xB20000, 0x990000, 0x800000, 0x660000,
	0x4C0000, 0x330000, 0x190000, 0x000000, 0xFF00FF,
	0x00FF00, 0x0000FF, 0xFFFF00, 0x00FFFF, 0xFF7F00,
	0xFF5F00, 0xFF3F00, 0xFF1F00, 0xFF0000};
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
			render.i = mandelbrot(render.x, render.y);
			if (render.i < MAX_ITER)
				my_mlx_pixel_put(fractol, render.a, render.b, get_color(render.i % 45));
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
	t_zoom	zoom;

	zoom.zoom = 2.0;
	if (botton == 4)
		zoom.zoom = 0.5;
	zoom.tmp0 = fractol->plan.x_max - fractol->plan.x_min;
	zoom.tmp1 = fractol->plan.y_max - fractol->plan.y_min;
	zoom.x_cord = (((x / 1000.0) * (fractol->plan.x_max - fractol->plan.x_min)) + fractol->plan.x_min);
	zoom.y_cord = (((-(y) / 1000.0) * (fractol->plan.y_max - fractol->plan.y_min)) + fractol->plan.y_max);
	fractol->plan.x_max = zoom.x_cord + ((fractol->plan.x_max - zoom.x_cord) * zoom.zoom);
	fractol->plan.x_min = fractol->plan.x_max - (zoom.tmp0 * zoom.zoom);
	fractol->plan.y_max = zoom.y_cord + ((fractol->plan.y_max - zoom.y_cord) * zoom.zoom);
	fractol->plan.y_min = fractol->plan.y_max - (zoom.tmp1 * zoom.zoom);
}

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
	if (botton == 53)
		close_window(fractol);
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
	mlx_hook(fractol->win, 17, 0, close_window, fractol);
	mlx_loop_hook(fractol->mlx, render, fractol);
	mlx_loop(fractol->mlx);
}
