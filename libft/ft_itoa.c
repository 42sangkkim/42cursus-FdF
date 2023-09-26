/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 20:28:58 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/24 11:54:49 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	ft_putnbr_buf(char *buffer, int n);
void		*ft_bzero(void *b, size_t n);
char		*ft_strdup(const char *s);
size_t		*ft_strlcat(char *dst, const char *src, size_t dst_size);

char	*ft_itoa(int n)
{
	char	buffer[12];
	char	*s;

	ft_bzero((char *)buffer, 12);
	ft_putnbr_buf((char *)buffer, n);
	s = ft_strdup((char *)buffer);
	if (!s)
		return (NULL);
	else
		return (s);
}

static void	ft_putnbr_buf(char *buffer, int n)
{
	int		upper;
	int		lower;
	char	digit_s[2];

	upper = n / 10;
	lower = n % 10;
	if (n < 0)
	{
		buffer[0] = '-';
		upper *= -1;
		lower *= -1;
	}
	if (upper)
		ft_putnbr_buf(buffer, upper);
	digit_s[0] = lower + '0';
	digit_s[1] = '\0';
	ft_strlcat(buffer, digit_s, 12);
}
