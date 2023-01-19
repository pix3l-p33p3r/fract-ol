/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 09:28:43 by elel-yak          #+#    #+#             */
/*   Updated: 2023/01/18 19:49:27 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "./includes/fractol.h"

void	my_mlx_pixel_put(t_fractol *fractol, int x, int y, int color)
{
	char	*dst;

	dst = fractol->image->addr + (y * fractol->image->line_length + x * (fractol->image->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	in_mandelbrot(long double x, long double y)
{
	long double z[5];
	int iteration;

	z[0] = 0;
	z[1] = 0;
	z[2] = x;
	z[3] = y;
	iteration = 0;
	while (z[0]*z[0] + z[1]*z[1] < 4 && iteration < MAX_ITER)
	{
		z[4] = z[0]*z[0] - z[1]*z[1] + z[2];
		z[1] = 2*z[0]*z[1] + z[3];
		z[0] = z[4];
		iteration++;
	}
	return (iteration);
}

int get_color(int i)
{
	const int colors[] = {
	0x000000, 0x000033, 0x000066, 0x000099, 0x0000cc, 
	0x0000ff, 0x3300ff, 0x6600ff, 0x9900ff, 0xcc00ff, 
	0xff00ff, 0xff00cc, 0xff0099, 0xff0066, 0xff0033,
	0xff0000, 0xff3300, 0xff6600, 0xff9900, 0xffff00
	};
	return colors[i];
}

int color_from_continuous_iterations(double x, double y, int iterations) {
    double color_index = (double)iterations + 1 - log2(log2(sqrt(x*x + y*y)));
    int color_index_int = (int)(color_index * 20);
    return get_color(color_index_int % 20);
}

int	render(t_fractol *fractol)
{
	long double x;
	long double y;
	int i;
	int a;
	int b;

	a = 0;
	mlx_destroy_image(fractol->mlx, fractol->image->img);
	fractol->image->img = mlx_new_image(fractol->mlx, 1000, 1000);
	fractol->image->addr = mlx_get_data_addr(fractol->image->img, &fractol->image->bits_per_pixel, &fractol->image->line_length,
								&fractol->image->endian);
	while (a < 1000)
	{
		x = (((a / 1000.0) * 6) - 3);
		b = 0;
		while (b < 1000)
		{
			y = (((-b / 1000.0) * 6) + 3);
			i = in_mandelbrot(x, y);
			if (i < MAX_ITER)
				my_mlx_pixel_put(fractol, a, b, get_color(i % 20));
			else
				my_mlx_pixel_put(fractol, a, b, 0);
			b++;
		}
		a++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->image->img, 0, 0);
	return (0);
}


unsigned int *inter()
{
	unsigned int *color_palette;

	color_palette = malloc(sizeof(unsigned int) * COLOR_COUNT);
	int	i = 0;
	int	j = 0x00000000;
	while (i < COLOR_COUNT)
	{
		color_palette[i] = j;
		j += 0x00000001;
		i++;
	}
	return (color_palette);
}


int	main(void)
{
	t_fractol	*fractol;

	fractol = malloc(sizeof(t_fractol));
	fractol->image = malloc(sizeof(t_image));
	
	fractol->mlx = mlx_init();
	fractol->win = mlx_new_window(fractol->mlx, 1000, 1000, "Mandelbrot Set");
	fractol->image->img = mlx_new_image(fractol->mlx, 1000, 1000);
	fractol->image->addr = mlx_get_data_addr(fractol->image->img, &fractol->image->bits_per_pixel, &fractol->image->line_length,
								&fractol->image->endian);


	fractol->color_palette = inter();

	mlx_loop_hook(fractol->mlx, render, fractol);
	mlx_loop(fractol->mlx);
}
