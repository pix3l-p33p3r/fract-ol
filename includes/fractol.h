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
# include <stdio.h>
# include "structs.h"

int			mandelbrot(long double x, long double y);
int			julia(t_julia cst, long double x, long double y);
int			mandelbrot_4(long double x, long double y);
void		ft_zoom(int botton, int x, int y, t_fractol *fractol);
int			get_color(int i);
void		ft_putstr(char *str);
int			ft_strcmp(char *s1, char *s2);
int			render(t_fractol *fractol);
void		init_render(t_fractol *fractol);
int			mouse_press(int button, int x, int y, t_fractol *fractol);
int			close_window(t_fractol *fractol);
int			botton_press(int botton, t_fractol *fractol);
void		init_cords(t_fractol *fractol, char **argv);
void		my_mlx_pixel_put(t_fractol *fractol, int x, int y, int color);
long double	ft_atof(const char *str);
t_julia		*ft_get_cst(t_julia *self);

#endif