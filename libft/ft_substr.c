/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:09:11 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/24 14:19:11 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dst_len);

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (s_len < start)
		return (ft_strdup(""));
	s_len -= (size_t)start;
	s += start;
	if (len > s_len)
		return (ft_strdup(s));
	else
	{
		sub_s = malloc((len + 1) * sizeof(char));
		if (!sub_s)
			return (NULL);
		ft_strlcpy(sub_s, s, len + 1);
		return (sub_s);
	}
}
