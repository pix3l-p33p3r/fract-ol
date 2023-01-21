/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 14:43:13 by elel-yak          #+#    #+#             */
/*   Updated: 2023/01/20 20:53:50 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <unistd.h>

# define COLOR_COUNT 20
# define MAX_ITER 1000

typedef struct s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_plan  {
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

#endif
