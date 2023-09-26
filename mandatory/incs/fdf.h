/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:21:15 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/07 03:26:03 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "config.h"
# include "map.h"

# define EVENT_CLOSE			17
# define EVENT_KEY_PRESS		2

# define KEY_ESC				53
# define KEY_SPACE				49

typedef struct s_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			rotation_flag;
	long		rotation;
	t_map		map;
	int			mode;
	t_point3	axis[3];
}	t_fdf;

#endif