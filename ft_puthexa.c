/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgolbert <wgolbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 15:10:50 by wgolbert          #+#    #+#             */
/*   Updated: 2026/06/29 19:09:23 by wgolbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_itoh(int n)
{
	if (n == 10)
		return ('a');
	if (n == 11)
		return ('b');
	if (n == 12)
		return ('c');
	if (n == 13)
		return ('d');
	if (n == 14)
		return ('e');
	if (n == 15)
		return ('f');
	else
		return (n + '0');
}

static char	*ft_converthexa(unsigned long n)
{
	char				*converted;
	int					i;
	unsigned long		temp;

	i = 0;
	temp = n;
	while (temp > 0)
	{
		temp = temp / 16;
		i++;
	}
	converted = malloc(sizeof(char) * (i + 1));
	converted[i] = '\0';
	temp = n;
	while (i > 0)
	{
		i--;
		converted[i] = ft_itoh (i % 16);
		temp = temp / 16;
	}
	return (converted);
}

static char	*ft_toupper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = (str[i] - 32);
	}
	return (str);
}

int	ft_puthexa(unsigned long n, int upper)
{
	char	*str;

	str = ft_converthexa(n);
	if (upper)
	{
		str = ft_toupper(str);
	}
	return (ft_putstr(str));
}
