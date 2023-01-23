/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_4th.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:07:14 by elel-yak          #+#    #+#             */
/*   Updated: 2023/01/23 12:39:53 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mandelbrot_4(long double x, long double y)
{
	t_mandelbrot_4	mandelbrot_4;

	mandelbrot_4.re_factor = x;
	mandelbrot_4.im_factor = y;
	mandelbrot_4.iter = 0;
	while (pow(mandelbrot_4.re_factor, 4) + pow(mandelbrot_4.im_factor, 4) < 4
		&& mandelbrot_4.iter < MAX_ITER)
	{
		mandelbrot_4.tmp = pow(mandelbrot_4.re_factor, 4) - 6
			* pow(mandelbrot_4.re_factor, 2)
			* pow(mandelbrot_4.im_factor, 2) + pow(mandelbrot_4.im_factor, 4)
			+ x;
		mandelbrot_4.im_factor = 4 * mandelbrot_4.re_factor
			* mandelbrot_4.im_factor * (pow(mandelbrot_4.re_factor, 2)
				- pow(mandelbrot_4.im_factor, 2)) + y;
		mandelbrot_4.re_factor = mandelbrot_4.tmp;
		mandelbrot_4.iter++;
	}
	return (mandelbrot_4.iter);
}
