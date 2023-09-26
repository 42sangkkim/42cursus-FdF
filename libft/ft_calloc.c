/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:22:51 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/24 15:54:57 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_bzero(void *b, size_t n);

void	*ft_calloc(size_t cnt, size_t size)
{
	void	*p;

	if (0x7FFFFFFFFFFFFFFFLL / cnt < size)
		return (NULL);
	p = malloc(cnt * size);
	if (!p)
		return (NULL);
	ft_bzero(p, cnt * size);
	return (p);
}
