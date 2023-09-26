/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:56:17 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/06 17:56:53 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	perallel_projection(t_point2 *d2, t_point3 d3)
{
	d2->x = d3.y;
	d2->y = d3.z;
}

int	one_point_projection(t_point2 *d2, double fov, t_point3 d3)
{
	double	distance;

	distance = fov - d3.x;
	if (distance <= 0)
		return (0);
	d2->x = d3.y / distance;
	d2->y = d3.z / distance;
	return (1);
}
