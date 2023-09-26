/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:21:15 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/07 02:58:18 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include "config_bonus.h"
# include "map_bonus.h"
# include "transform_bonus.h"

# define EVENT_CLOSE			17
# define EVENT_KEY_PRESS		2

# define KEY_ESC				53
# define KEY_PLUS				24
# define KEY_MINUS				27
# define KEY_UP_ARROW			126
# define KEY_DOWN_ARROW			125
# define KEY_LEFT_ARROW			123
# define KEY_RIGHT_ARROW		124
# define KEY_1					18
# define KEY_2					19
# define KEY_Q					12
# define KEY_W					13
# define KEY_E					14
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2

# define BUTTON_SCROLL_UP		5
# define BUTTON_SCROLL_DOWN		4

# define PERALLEL_PROJECTION	0
# define ONE_POINT_PROJECTION	1

typedef struct s_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*axis_bg;
	t_map		map;
	t_transform	transform;
	int			mode;
	t_point3	axis[3];
}	t_fdf;

#endif