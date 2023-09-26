/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_transform_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:11:26 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/07 00:44:36 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	init_transform(t_transform *transform, double max_x)
{
	transform->fov = max_x * 1.5;
	transform->zoom = 20.0;
	transform->dx = 0.0;
	transform->dy = 0.0;
	transform->quaternion.w = 1.0;
	transform->quaternion.x = 0.0;
	transform->quaternion.y = 0.0;
	transform->quaternion.z = 0.0;
}
