/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:16:19 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/24 11:15:16 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c);

int	ft_atoi(const char *s)
{
	int	value;
	int	sign;

	while (*s == '\t' || *s == '\n' || *s == '\v'
		|| *s == '\f' || *s == '\r' || *s == ' ')
		s++;
	if (*s == '-')
		sign = -1;
	else
		sign = 1;
	if (*s == '-' || *s == '+')
		s++;
	value = 0;
	while (ft_isdigit(*s))
	{
		value = (value * 10) + (*s - '0') * sign;
		s++;
	}
	return (value);
}	
