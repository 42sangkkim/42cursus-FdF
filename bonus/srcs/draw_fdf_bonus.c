/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fdf_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:21:36 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/07 02:51:14 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx.h>
#include "fdf_bonus.h"
#include "utils.h"

void	draw_axis(t_fdf *fdf);
void	draw_line(t_fdf *fdf, t_edge edge1, t_edge edge2);

void	draw_fdf(t_fdf *fdf)
{
	size_t	i;
	size_t	j;

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
	draw_axis(fdf);
}

void	draw_axis(t_fdf *fdf)
{
	t_edge		origin;
	t_edge		end;

	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr,
		fdf->axis_bg, 1100, 10);
	origin.d2.x = 1185;
	origin.d2.y = 95;
	end.d2.x = origin.d2.x + fdf->axis[0].y;
	end.d2.y = origin.d2.y - fdf->axis[0].z;
	end.color.value = 0xFF0000;
	origin.color.value = 0xFF0000;
	draw_line (fdf, origin, end);
	end.d2.x = origin.d2.x + fdf->axis[1].y;
	end.d2.y = origin.d2.y - fdf->axis[1].z;
	end.color.value = 0x00FF00;
	origin.color.value = 0x00FF00;
	draw_line (fdf, origin, end);
	end.d2.x = origin.d2.x + fdf->axis[2].y;
	end.d2.y = origin.d2.y - fdf->axis[2].z;
	end.color.value = 0x0000FF;
	origin.color.value = 0x0000FF;
	draw_line (fdf, origin, end);
}

void	draw_line(t_fdf *fdf, t_edge edge1, t_edge edge2)
{
	size_t		i;
	size_t		dt;
	t_point2	point;
	t_point2	delta;

	if (!edge1.drawable || !edge2.drawable)
		return ;
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
