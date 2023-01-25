/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 09:56:23 by elel-yak          #+#    #+#             */
/*   Updated: 2023/01/25 22:35:56 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_julia	*ft_get_cst(t_julia *self)
{
	static t_julia	*cst;

	if (!cst)
		cst = self;
	return (cst);
}

void	init_cords(t_fractol *fractol, char **argv)
{
	t_julia	julia;

	fractol->plan.x_min = -3.0;
	fractol->plan.x_max = 3.0;
	fractol->plan.y_min = -3.0;
	fractol->plan.y_max = 3.0;
	if (argv[2] && argv[3])
	{
		julia.im_factor = ft_atof(argv[2]);
		julia.re_factor = ft_atof(argv[3]);
		fractol->julia = julia;
	}
}
