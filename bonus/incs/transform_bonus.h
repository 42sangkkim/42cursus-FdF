/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:49:16 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/06 23:26:57 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_BONUS_H
# define TRANSFORM_BONUS_H

typedef struct s_quaternion
{
	double	w;
	double	x;
	double	y;
	double	z;
}	t_quaternion;

typedef struct s_transform
{
	double			fov;
	double			zoom;
	double			dx;
	double			dy;
	t_quaternion	quaternion;
	double			rotation_vector[3][3];
}	t_transform;

#endif