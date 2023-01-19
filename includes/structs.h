/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 14:43:13 by elel-yak          #+#    #+#             */
/*   Updated: 2023/01/19 19:54:15 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <unistd.h>

# define COLOR_COUNT 20
# define MAX_ITER 100

typedef struct s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_fractol {
	void			*mlx;
	void			*win;
	unsigned int	*color_palette;
	t_image			*image;
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
