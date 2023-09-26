/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:47:27 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/07 03:15:49 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map.h"
#include "utils.h"

void	parse_xy(t_map *map);
void	parse_z(t_map *map, char ***file_data);
void	parse_color(t_map *map, char ***file_data);

void	init_map(t_map *map, char ***file_data)
{
	map->height = ft_arrlen((void **)file_data);
	map->width = ft_arrlen((void **)*file_data);
	map->edges = (t_edge **)malloc_array(
			map->height, map->width, sizeof(t_edge));
	if (!map->edges)
		exit_msg("[ERROR] malloc error\n");
	parse_xy(map);
	parse_z(map, file_data);
	parse_color(map, file_data);
}

void	parse_xy(t_map *map)
{
	size_t	i;
	size_t	j;
	double	oi;
	double	oj;

	oi = (double)(map->height - 1) / 2.;
	oj = (double)(map->width - 1) / 2.;
	map->min_edge.x = -oi;
	map->min_edge.y = -oj;
	map->max_edge.x = oi;
	map->max_edge.y = oj;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->edges[i][j].d3.x = (double)i - oi;
			map->edges[i][j].d3.y = (double)j - oj;
			j++;
		}
		i++;
	}
}

void	parse_z(t_map *map, char ***file_data)
{
	size_t	i;
	size_t	j;

	map->min_edge.z = ft_atoi(file_data[0][0]);
	map->max_edge.z = ft_atoi(file_data[0][0]);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->edges[i][j].d3.z = ft_atoi(file_data[i][j]);
			if (map->min_edge.z > map->edges[i][j].d3.z)
				map->min_edge.z = map->edges[i][j].d3.z;
			if (map->max_edge.z < map->edges[i][j].d3.z)
				map->max_edge.z = map->edges[i][j].d3.z;
			j++;
		}
		i++;
	}
}

void	parse_color(t_map *map, char ***file_data)
{
	size_t	i;
	size_t	j;
	double	z_gap;

	z_gap = map->max_edge.z - map->min_edge.z;
	if (z_gap == 0.)
		z_gap = 1.;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (ft_strchr(file_data[i][j], ','))
				map->edges[i][j].color.value
					= ft_atoi_hex(
						(const char*)ft_strchr(file_data[i][j], 'x') + 1);
			else
				map->edges[i][j].color = mix_color(
						(t_color)MIN_COLOR, (t_color)MAX_COLOR,
						(map->edges[i][j].d3.z - map->min_edge.z) / z_gap);
			j++;
		}
		i++;
	}
}
