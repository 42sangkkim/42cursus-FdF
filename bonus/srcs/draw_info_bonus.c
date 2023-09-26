/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_info_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 01:24:25 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/07 01:28:09 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft.h"
#include "fdf_bonus.h"

void	draw_status(t_fdf *fdf);
void	build_info(char *buffer, char *prefix, double value, char *suffix);
size_t	build_int_buffer(char *buffer, size_t p, int value);

void	draw_info(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 0, 0, TEXT_COLOR,
		"Arrows : move");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 0, 20, TEXT_COLOR,
		"Scroll : zoom in/out");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 0, 40, TEXT_COLOR,
		"     1 : perallel projection");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 0, 60, TEXT_COLOR,
		"     2 : one point projection");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 0, 80, TEXT_COLOR,
		"   + - : fov");
	draw_status(fdf);
}

void	draw_status(t_fdf *fdf)
{
	char	buffer[100];

	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 0, 120, TEXT_COLOR,
		"Current Status");
	if (fdf->mode == PERALLEL_PROJECTION)
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 40, 140, TEXT_COLOR,
			"mode : perallel projection");
	else
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 40, 140, TEXT_COLOR,
			"mode : one point projection");
	build_info(buffer, " fov : ", fdf->transform.fov, "");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 40, 160, TEXT_COLOR,
		buffer);
	build_info(buffer, "  dx : ", fdf->transform.dx, "");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 40, 180, TEXT_COLOR,
		buffer);
	build_info(buffer, "  dy : ", fdf->transform.dy, "");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 40, 200, TEXT_COLOR,
		buffer);
	build_info(buffer, "zoom : ", fdf->transform.zoom, " X");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 40, 220, TEXT_COLOR,
		buffer);
}

void	build_info(char *buffer, char *prefix, double value, char *suffix)
{
	buffer[0] = '\0';
	ft_strlcat(buffer, prefix, 100);
	if (value < 0)
	{
		ft_strlcat(buffer, "-", 100);
		value *= -1;
	}
	build_int_buffer(buffer, ft_strlen(buffer), (int)value);
	ft_strlcat(buffer, ".", 100);
	build_int_buffer(buffer, ft_strlen(buffer), (int)(value * 100) % 100);
	ft_strlcat(buffer, suffix, 100);
}

size_t	build_int_buffer(char *buffer, size_t p, int value)
{
	if (value >= 10)
		p = build_int_buffer(buffer, p, value / 10);
	buffer[p] = value % 10 + '0';
	buffer[p + 1] = '\0';
	return (p + 1);
}
