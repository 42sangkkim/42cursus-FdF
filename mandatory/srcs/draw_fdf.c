/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:21:36 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/07 03:51:41 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx.h>
#include "fdf.h"
#include "utils.h"

void	draw_line(t_fdf *fdf, t_edge edge1, t_edge edge2);

void	draw_fdf(t_fdf *fdf)
{
	size_t	i;
	size_t	j;

	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	i = 0;
	while (i < fdf->map.height)
	{
		j = 0;
		while (j < fdf->map.width)
		{
			if (i)
				draw_line(fdf, fdf->map.edges[i - 1][j], fdf->map.edges[i][j]);
			if (j)
				draw_line(fdf, fdf->map.edges[i][j - 1], fdf->map.edges[i][j]);
			j++;
		}
		i++;
	}
}

void	draw_line(t_fdf *fdf, t_edge edge1, t_edge edge2)
{
	size_t		i;
	size_t		dt;
	t_point2	point;
	t_point2	delta;

	point.x = edge1.d2.x;
	point.y = edge1.d2.y;
	dt = (size_t)fmax(
			fabs(edge2.d2.x - edge1.d2.x),
			fabs(edge2.d2.y - edge1.d2.y));
	delta.x = (edge2.d2.x - edge1.d2.x) / dt;
	delta.y = (edge2.d2.y - edge1.d2.y) / dt;
	i = 0;
	while (i <= dt)
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr,
			(int)point.x, (int)point.y,
			mix_color(edge1.color, edge2.color,
				(double)i / (double)dt).value);
		point.x += delta.x;
		point.y += delta.y;
		i += 1;
	}
}
