/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 20:01:23 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/24 16:02:07 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char			*ft_strchr(const char *s, int c);
char			*ft_substr(const char *s, unsigned int start, size_t len);
static void		free_strarr(char **arr);
static size_t	count_word(const char *s, char c);

char	**ft_split(const char *s, char c)
{
	char	**words;
	size_t	word_count;
	size_t	len;
	size_t	i;

	word_count = count_word(s, c);
	words = calloc(word_count + 1, sizeof(char *));
	if (!words)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		while (*s == c)
			s++;
		len = (size_t)(ft_strchr(s, c) - s);
		words[i] = ft_substr(s, 0, len);
		if (!words[i])
		{
			free_strarr(words);
			return (NULL);
		}
		s = ft_strchr(s, c);
		i++;
	}
	return (words);
}

static void	free_strarr(char **arr)
{
	char	*p;

	p = *arr;
	while (p)
		free(p++);
	free(arr);
}

static size_t	count_word(const char *s, char c)
{
	size_t	cnt;

	cnt = 0;
	if (*s != c)
		cnt++;
	while (*s)
	{
		if (*s == c && *(s + 1) && *(s + 1) != c)
			cnt++;
		s++;
	}
	return (cnt);
}
