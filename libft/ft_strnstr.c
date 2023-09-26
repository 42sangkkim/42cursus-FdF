/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:32:43 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/24 15:04:27 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	haystack_len;
	size_t	needle_len;

	haystack_len = 0;
	while (haystack[haystack_len] && haystack_len < n)
		haystack_len++;
	needle_len = ft_strlen(needle);
	while (needle_len <= haystack_len--)
	{
		if (!ft_strncmp(haystack, needle, needle_len))
			return ((char *)(haystack));
		haystack++;
	}
	return (NULL);
}
