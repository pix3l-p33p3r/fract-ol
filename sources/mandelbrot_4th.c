/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_4th.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:07:14 by elel-yak          #+#    #+#             */
/*   Updated: 2023/01/23 13:23:30 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mandelbrot_4(long double x, long double y)
{
	t_mandelbrot_4	mandel;

	mandel.re = 0;
	mandel.im = 0;
	mandel.re_factor = x;
	mandel.im_factor = y;
	mandel.iter = 0;
	while ((pow(mandel.re, 4) + pow(mandel.im, 4)) < 4
		&& mandel.iter < MAX_ITER)
	{
		mandel.tmp = pow(mandel.re, 4) - 6 * pow(mandel.re, 2)
			* pow(mandel.im, 2) + pow(mandel.im, 4) + mandel.re_factor;
		mandel.im = 4 * pow(mandel.re, 3) * mandel.im - 4 * mandel.re
			* pow(mandel.im, 3) + mandel.im_factor;
		mandel.re = mandel.tmp;
		mandel.iter++;
	}
	return (mandel.iter);
}
