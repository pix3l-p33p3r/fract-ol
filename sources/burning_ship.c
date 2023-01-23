/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:07:14 by elel-yak          #+#    #+#             */
/*   Updated: 2023/01/23 10:08:24 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	burningship(long double x, long double y)
{
	t_burningship	burningship;

	burningship.re_factor = x;
	burningship.im_factor = y;
	burningship.iter = 0;
	while (((pow(burningship.re_factor, 2)) + (pow(burningship.im_factor, 2))) < 4
		&& burningship.iter < MAX_ITER)
	{
		burningship.tmp = pow(burningship.re_factor, 2) - pow(burningship.im_factor, 2) + 0.0;
		burningship.im_factor = 2 * fabs(burningship.re_factor * burningship.im_factor) - 0.8;
		burningship.re_factor = burningship.tmp;
		burningship.iter++;
	}
	return (burningship.iter);
}