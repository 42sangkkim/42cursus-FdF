/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:10:02 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/24 15:10:19 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_p;
	unsigned char	*src_p;

	if (dst == src)
		return (dst);
	dst_p = (unsigned char *)dst;
	src_p = (unsigned char *)src;
	while (n--)
		*dst_p++ = *src_p++;
	return (dst);
}
