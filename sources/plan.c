/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 09:56:23 by elel-yak          #+#    #+#             */
/*   Updated: 2023/01/23 09:56:31 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_cords(t_fractol *fractol)
{
	fractol->plan.x_min = -3.0;
	fractol->plan.x_max = 3.0;
	fractol->plan.y_min = -3.0;
	fractol->plan.y_max = 3.0;
}
