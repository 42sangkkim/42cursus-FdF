/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:05:07 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/07 03:41:32 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include "fdf.h"

// utils1.c
size_t	ft_arrlen(void **arr);
void	free_array(void **arr);
void	free_double_array(void ***darr);
void	**malloc_array(size_t height, size_t width, size_t size);
void	*ft_realloc(void *src, size_t src_size, size_t dst_size);

// utils2.c
void	exit_msg(char *msg);
t_color	mix_color(t_color c1, t_color c2, double ratio);
int		ft_atoi_hex(const char *s);

#endif
