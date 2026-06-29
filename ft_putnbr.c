/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgolbert <wgolbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 13:17:28 by wgolbert          #+#    #+#             */
/*   Updated: 2026/06/29 14:01:00 by wgolbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digit(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
	{
		n *= -1;
		count++;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*ft_itoa(int n)
{
	int		count;
	int		temp;
	char	*str;

	count = count_digit(n);
	str = malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	str[count] = '\0';
	temp = n;
	while (temp > 0)
	{
		count--;
		str[count] = (temp % 10) + '0';
		temp = temp / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

int	ft_putnbr(int n)
{
	int		count;
	char	*str;

	count = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n == 0)
		return (ft_putstr("0"));
	str = ft_itoa(n);
	count = ft_putstr (str);
	return (count);
}
