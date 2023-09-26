/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:16:35 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/20 16:21:55 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t dst_len);

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*join;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	join = malloc((len1 + len2 + 1) * sizeof(char));
	if (!join)
		return (NULL);
	*join = '\0';
	ft_strlcat(join, s1, len1 + len2 + 1);
	ft_strlcat(join, s2, len1 + len2 + 1);
	return (join);
}
