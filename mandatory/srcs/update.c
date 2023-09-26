/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:18:10 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/07 03:52:39 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

void	rotate(t_point3 *to, t_point3 from, double cos, double sin);
void	isometric_projection(t_point2 *d2, t_point3 d3);

void	update(t_fdf *fdf)
{
	size_t		i;
	size_t		j;
	t_point3	tmp;
	double		cos_theta;
	double		sin_theta;

	cos_theta = cos((double)fdf->rotation / (double)ROTATE_RESOLUTION * M_PI);
	sin_theta = sin((double)fdf->rotation / (double)ROTATE_RESOLUTION * M_PI);
	i = 0;
	while (i < fdf->map.height)
	{
		j = 0;
		while (j < fdf->map.width)
		{
			rotate(&tmp, fdf->map.edges[i][j].d3, cos_theta, sin_theta);
			isometric_projection(&(fdf->map.edges[i][j].d2), tmp);
			j++;
		}
		i++;
	}
}

void	rotate(t_point3 *to, t_point3 from, double cos, double sin)
{
	to->x = from.x * cos - from.y * sin;
	to->y = from.x * sin + from.y * cos;
	to->z = from.z;
}

void	isometric_projection(t_point2 *d2, t_point3 d3)
{
	const double	cos30 = cos(M_PI_2 / 3.);
	const double	sin30 = sin(M_PI_2 / 3.);

	d2->x = (double)SCREEN_WIDTH / 2. + cos30 * (d3.y - d3.x) * 20.;
	d2->y = (double)SCREEN_HEIGHT / 2. - (d3.z - sin30 * (d3.x + d3.y)) * 20.;
}
