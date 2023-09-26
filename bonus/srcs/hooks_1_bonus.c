/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_1_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:19:01 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/06 23:37:01 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <math.h>
#include "fdf_bonus.h"

void	key_hook_2(int keycode, t_fdf *fdf);
void	rotate_quaternion(t_quaternion *q,
			double x, double y, double z);
int		close_hook(void *param);

int	key_hook(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (keycode == KEY_ESC)
		close_hook(fdf);
	else if (keycode == KEY_PLUS)
		fdf->transform.fov += D_FOV;
	else if (keycode == KEY_MINUS)
		fdf->transform.fov -= D_FOV;
	else if (keycode == KEY_UP_ARROW)
		fdf->transform.dy += D_TRANSLATE;
	else if (keycode == KEY_DOWN_ARROW)
		fdf->transform.dy -= D_TRANSLATE;
	else if (keycode == KEY_LEFT_ARROW)
		fdf->transform.dx -= D_TRANSLATE;
	else if (keycode == KEY_RIGHT_ARROW)
		fdf->transform.dx += D_TRANSLATE;
	else if (keycode == KEY_1)
		fdf->mode = PERALLEL_PROJECTION;
	else if (keycode == KEY_2)
		fdf->mode = ONE_POINT_PROJECTION;
	else
		key_hook_2(keycode, fdf);
	return (keycode);
}

void	key_hook_2(int keycode, t_fdf *fdf)
{
	const double	sin_pi_24 = sin(M_PI_4 / 6);

	if (keycode == KEY_Q)
		rotate_quaternion(&(fdf->transform.quaternion),
			sin_pi_24, 0, 0);
	else if (keycode == KEY_W)
		rotate_quaternion(&(fdf->transform.quaternion),
			0, -sin_pi_24, 0);
	else if (keycode == KEY_E)
		rotate_quaternion(&(fdf->transform.quaternion),
			-sin_pi_24, 0, 0);
	else if (keycode == KEY_A)
		rotate_quaternion(&(fdf->transform.quaternion),
			0, 0, -sin_pi_24);
	else if (keycode == KEY_S)
		rotate_quaternion(&(fdf->transform.quaternion),
			0, sin_pi_24, 0);
	else if (keycode == KEY_D)
		rotate_quaternion(&(fdf->transform.quaternion),
			0, 0, sin_pi_24);
}

void	rotate_quaternion(t_quaternion *q,
	double x, double y, double z)
{
	const double	cos_pi_24 = cos(M_PI_4 / 6);
	double			tmp[4];

	tmp[0] = cos_pi_24 * q->w - x * q->x - y * q->y - z * q->z;
	tmp[1] = cos_pi_24 * q->x + x * q->w + y * q->z - z * q->y;
	tmp[2] = cos_pi_24 * q->y - x * q->z + y * q->w + z * q->x;
	tmp[3] = cos_pi_24 * q->z + x * q->y - y * q->x + z * q->w;
	q->w = tmp[0];
	q->x = tmp[1];
	q->y = tmp[2];
	q->z = tmp[3];
}

int	close_hook(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	write(1, "good bye~!\n", 11);
	exit(0);
}
