/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 09:32:09 by elel-yak          #+#    #+#             */
/*   Updated: 2023/01/23 09:39:12 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mandelbrot(long double x, long double y)
{
	t_mandel	mandel;

	mandel.re = 0;
	mandel.im = 0;
	mandel.re_factor = x;
	mandel.im_factor = y;
	mandel.iter = 0;
	while (((pow(mandel.re, 2)) + (pow(mandel.im, 2))) < 4
		&& mandel.iter < MAX_ITER)
	{
		mandel.tmp = pow(mandel.re, 2) - pow(mandel.im, 2) + mandel.re_factor;
		mandel.im = 2 * mandel.re * mandel.im + mandel.im_factor;
		mandel.re = mandel.tmp;
		mandel.iter++;
	}
	return (mandel.iter);
}
