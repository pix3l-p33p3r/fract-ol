/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 09:39:22 by elel-yak          #+#    #+#             */
/*   Updated: 2023/01/25 22:35:34 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	julia(t_julia cst, long double x, long double y)
{
	t_julia	julia;

	julia.re_factor = x;
	julia.im_factor = y;
	julia.iter = 0;
	while (((pow(julia.re_factor, 2)) + (pow(julia.im_factor, 2))) < 4
		&& julia.iter < MAX_ITER)
	{
		julia.tmp = pow(julia.re_factor, 2) - pow(julia.im_factor, 2)
			+ cst.re_factor;
		julia.im_factor = 2 * julia.re_factor * julia.im_factor + cst.im_factor;
		julia.re_factor = julia.tmp;
		julia.iter++;
	}
	return (julia.iter);
}
