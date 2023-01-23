/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 14:43:13 by elel-yak          #+#    #+#             */
/*   Updated: 2023/01/23 10:09:03 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define MAX_ITER 100

typedef struct s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_plan {
	long double	x_min;
	long double	y_min;
	long double	x_max;
	long double	y_max;
}	t_plan;

typedef struct s_fractol {
	void			*mlx;
	void			*win;
	t_image			*image;
	t_plan			plan;
}	t_fractol;

typedef struct s_render {
	long double	x;
	long double	y;
	int			a;
	int			b;
	int			i;
}				t_render;

typedef struct s_mandel {
	long double	re;
	long double	im;
	long double	re_factor;
	long double	im_factor;
	long double	tmp;
	int			iter;
}				t_mandel;

typedef struct s_julia {
	long double	re_factor;
	long double	im_factor;
	long double	tmp;
	int			iter;
}				t_julia;

typedef struct s_burningship {
	long double	re;
	long double	im;
	long double	re_factor;
	long double	im_factor;
	long double	tmp;
	int			iter;
}				t_burningship;

typedef struct s_zoom {
	long double	x_cord;
	long double	y_cord;
	long double	zoom;
	long double	tmp0;
	long double	tmp1;
	long double	tmp2;
}				t_zoom;

#endif
