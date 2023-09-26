/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:23:10 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/06 17:49:03 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_BONUS_H
# define MAP_BONUS_H

# include <stdlib.h>

typedef struct s_point3
{
	double	x;
	double	y;
	double	z;
}	t_point3;

typedef struct s_point2
{
	double	x;
	double	y;
}	t_point2;

typedef union u_color
{
	int	value;
	struct s_rgb
	{
		unsigned char	b;
		unsigned char	g;
		unsigned char	r;
	}	rgb;
}	t_color;

typedef struct s_edge
{
	int			drawable;
	t_point3	d3;
	t_point2	d2;
	t_color		color;
}	t_edge;

typedef struct s_map
{
	size_t		height;
	size_t		width;
	t_edge		**edges;
	t_point3	max_edge;
	t_point3	min_edge;
}	t_map;

#endif
