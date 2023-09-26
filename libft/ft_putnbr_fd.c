/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 20:56:07 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/23 20:58:38 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	int		upper;
	int		lower;
	char	digit;

	upper = n / 10;
	lower = n % 10;
	if (n < 0)
	{
		upper *= -1;
		lower *= -1;
		write(fd, "-", 1);
	}
	if (upper)
		ft_putnbr_fd(upper, fd);
	digit = lower + '0';
	write(fd, &digit, 1);
}
