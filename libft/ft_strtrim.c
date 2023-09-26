/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:22:08 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/23 21:53:50 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(const char *s, unsigned int start, size_t len);

char	*ft_strtrim(const char *s1, const char *set)
{
	unsigned int	start;
	size_t			len;
	char			*s2;

	start = 0;
	while (ft_strchr(set, s1[start]))
		start++;
	len = ft_strlen(s1 + start);
	while (ft_strchr(set, s1[start + len - 1]))
		len--;
	s2 = ft_substr(s1, start, len);
	if (!s2)
		return (NULL);
	else
		return (s2);
}
