/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:10:11 by elel-yak          #+#    #+#             */
/*   Updated: 2023/01/25 22:39:45 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

long double	ft_atof(const char *str)
{
	long double		res;
	long double		dec;
	int				i;
	long double		sign;

	i = 0;
	res = 0.0;
	dec = 1.0;
	sign = 1.0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = 1.0 - 2.0 * (str[i++] == '-');
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10.0 + str[i++] - '0';
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10.0 + str[i++] - '0';
		dec *= 10.0;
	}
	res /= dec;
	return (res * sign);
}
