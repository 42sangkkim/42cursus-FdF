/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 01:09:55 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/05 17:59:57 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft.h"
#include "fdf_bonus.h"

void	exit_msg(char *msg)
{
	perror(msg);
	exit(-1);
}

t_color	mix_color(t_color c1, t_color c2, double ratio)
{
	t_color	color;
	double	r_ratio;

	r_ratio = 1 - ratio;
	color.value = 0;
	color.rgb.r = (unsigned char)
		((double)c1.rgb.r * r_ratio + (double)c2.rgb.r * ratio);
	color.rgb.g = (unsigned char)
		((double)c1.rgb.g * r_ratio + (double)c2.rgb.g * ratio);
	color.rgb.b = (unsigned char)
		((double)c1.rgb.b * r_ratio + (double)c2.rgb.b * ratio);
	return (color);
}

int	ft_atoi_hex(const char *s)
{
	int	value;

	value = 0;
	while (*s)
	{
		if (ft_isdigit(*s))
			value = value * 16 + (*s - '0');
		else if ('A' <= *s && *s <= 'F')
			value = value * 16 + (*s - 'A' + 10);
		else if ('a' <= *s && *s <= 'f')
			value = value * 16 + (*s - 'a' + 10);
		else
			break ;
		s++;
	}
	return (value);
}
