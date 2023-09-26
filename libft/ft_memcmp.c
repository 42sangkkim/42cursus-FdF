/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:17:57 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/24 15:11:06 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *b1, const void *b2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	if (b1 == b2)
		return (0);
	p1 = (unsigned char *)b1;
	p2 = (unsigned char *)b2;
	while (n--)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
	}
	return (0);
}
