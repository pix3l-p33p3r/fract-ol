/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 09:33:27 by elel-yak          #+#    #+#             */
/*   Updated: 2023/01/23 11:17:33 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	get_color(int i)
{
	const int	colors[45] = {0x000020, 0x000040, 0x000060, 0x000080, 0x0000A0,
		0x0000C0, 0x0000E0, 0x0000FF, 0x1A1AFF, 0x3F3FFF,
		0x5F5FFF, 0x8F8FFF, 0xAFAFFF, 0xCFCFFF, 0xEFEFFF,
		0xFFFFFF, 0xFFEFEF, 0xFFCFCF, 0xFFAFAF, 0xFF8F8F,
		0xFF6F6F, 0xFF3F3F, 0xFF1A1A, 0xFF0000, 0xE50000,
		0xCC0000, 0xB20000, 0x990000, 0x800000, 0x660000,
		0x4C0000, 0x330000, 0x190000, 0x000000, 0xFF00FF,
		0x00FF00, 0x0000FF, 0xFFFF00, 0x00FFFF, 0xFF7F00,
		0xFF5F00, 0xFF3F00, 0xFF1F00, 0xFF0000};

	return (colors[i]);
}
