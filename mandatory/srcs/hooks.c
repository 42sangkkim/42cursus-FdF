/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:19:01 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/07 03:53:50 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <math.h>
#include "fdf.h"

void	draw_fdf(t_fdf *fdf);
void	update(t_fdf *fdf);

int		close_hook(void *param);

int	key_hook(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (keycode == KEY_ESC)
		close_hook(fdf);
	else if (keycode == KEY_SPACE)
		fdf->rotation_flag = !(fdf->rotation_flag);
	return (keycode);
}

int	close_hook(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	write(1, "good bye~!\n", 11);
	exit(0);
}

int	loop_hook(void *param)
{
	static long	prev_rotation;
	t_fdf		*fdf;

	fdf = (t_fdf *)param;
	if (fdf->rotation_flag)
		fdf->rotation++;
	if (fdf-> rotation > 2 * ROTATE_RESOLUTION)
		fdf-> rotation -= 2 * ROTATE_RESOLUTION;
	if (prev_rotation != fdf->rotation)
	{
		prev_rotation = fdf->rotation;
		update(fdf);
		draw_fdf(fdf);
		return (1);
	}
	return (0);
}
