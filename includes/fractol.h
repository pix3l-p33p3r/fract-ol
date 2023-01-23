/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 14:35:30 by elel-yak          #+#    #+#             */
/*   Updated: 2022/12/31 14:37:59 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include "structs.h"

int	mandelbrot(long double x, long double y);
int	julia(long double x, long double y);
int	burning_ship(long double x, long double y);
void ft_zoom(int botton, int x, int y, t_fractol *fractol);
int	get_color(int i);
void	ft_putstr(char *str);
int	ft_strcmp(char *s1, char *s2);
int	render(t_fractol *fractol);
void	init_render(void);
int mouse_press(int button, int x, int y, t_fractol *fractol);
int 	close_window(t_fractol *fractol);
int 	botton_press(int botton, t_fractol *fractol);
void 	init_cords(t_fractol *fractol);
void	my_mlx_pixel_put(t_fractol *fractol, int x, int y, int color);


#endif