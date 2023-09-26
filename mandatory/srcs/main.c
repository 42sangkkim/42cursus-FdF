/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:20:28 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/07 04:29:34 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <mlx.h>
#include "libft.h"
#include "fdf.h"
#include "utils.h"

void	init_map(t_map *map, char ***file_data);
char	***get_file_data(char *filename);
int		check_file_data(char ***words);

void	draw_fdf(t_fdf *fdf);
void	update(t_fdf *fdf);

int		key_hook(int keycode, void *param);
int		close_hook(void *param);
int		loop_hook(void *param);

void	init_fdf(t_fdf *fdf, char ***file_data);
void	init_mlx(t_fdf *fdf, char *file_name);

int	main(int argc, char **argv)
{
	t_fdf	fdf;
	char	***file_data;

	if (argc != 2)
	{
		write(1, "fdf get one parameter, which is filename\n", 41);
		return (0);
	}
	file_data = get_file_data(argv[1]);
	if (!check_file_data(file_data))
		return (0);
	init_fdf(&fdf, file_data);
	free_double_array((void ***)file_data);
	init_mlx(&fdf, argv[1]);
	update(&fdf);
	draw_fdf(&fdf);
	mlx_loop(fdf.mlx_ptr);
	return (0);
}

void	init_fdf(t_fdf *fdf, char ***file_data)
{
	ft_bzero(fdf, sizeof(t_fdf));
	init_map(&(fdf->map), file_data);
}

void	init_mlx(t_fdf *fdf, char *file_name)
{
	fdf->mlx_ptr = mlx_init();
	if (!fdf->mlx_ptr)
		exit_msg("[ERROR] mlx didn't created\n");
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr,
			SCREEN_WIDTH, SCREEN_HEIGHT, file_name);
	if (!fdf->win_ptr)
		exit_msg("[ERROR] window didn't created\n");
	mlx_hook(fdf->win_ptr, EVENT_KEY_PRESS, 0, &key_hook, fdf);
	mlx_loop_hook(fdf->mlx_ptr, &loop_hook, fdf);
	mlx_hook(fdf->win_ptr, EVENT_CLOSE, 0, &close_hook, fdf);
}
