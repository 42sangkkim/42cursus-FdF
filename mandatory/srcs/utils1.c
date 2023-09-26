/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:53:28 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/04 23:49:02 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "libft.h"

size_t	ft_arrlen(void **arr)
{
	size_t	len;

	len = 0;
	while (*arr++)
		len++;
	return (len);
}

void	free_array(void	**arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	free_double_array(void ***darr)
{
	size_t	i;

	i = 0;
	while (darr[i])
		free_array(darr[i++]);
	free(darr);
}

void	**malloc_array(size_t height, size_t width, size_t size)
{
	size_t	i;
	void	**arr;

	arr = malloc((height + 1) * sizeof(void *));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < height)
	{
		arr[i] = malloc(width * size);
		if (!arr[i])
		{
			free_array(arr);
			return (NULL);
		}
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

void	*ft_realloc(void *src, size_t src_size, size_t dst_size)
{
	void	*dst;

	dst = malloc(dst_size);
	if (!dst)
	{
		free(src);
		return (NULL);
	}
	ft_memcpy(dst, src, src_size);
	free(src);
	return (dst);
}
