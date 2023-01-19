/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 14:43:13 by elel-yak          #+#    #+#             */
/*   Updated: 2023/01/18 20:55:53 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef STRUCTS_H
# define STRUCTS_H

# include <unistd.h>

# define COLOR_COUNT 20
# define MAX_ITER 10000

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

int get_color_smooth(double value);

#endif
