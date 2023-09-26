/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:12:29 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/24 15:58:35 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_p;
	unsigned char	*src_p;

	if (dst == src)
		return (dst);
	dst_p = (unsigned char *)dst;
	src_p = (unsigned char *)src;
	if (dst < src)
	{
		while (n--)
			*dst_p++ = *src_p++;
	}
	else
	{
		while (n--)
			dst_p[n] = src_p[n];
	}
	return (dst);
}
