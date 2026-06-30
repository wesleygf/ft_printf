/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgolbert <wgolbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 13:02:24 by wgolbert          #+#    #+#             */
/*   Updated: 2026/06/29 19:11:58 by wgolbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_convert(char c, va_list args)
{
	if (c == 'c')
	{
		ft_putchar(va_arg(args, char));
		return (1);		
	}
	if (c == 's')
		return (ft_putstr(""));
	if (c == 'p')
		return (ft_putptr(va_arg(args, void *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'x')
		return (ft_puthexa(va_arg(args, unsigned int), 0));
	if (c == 'X')
		return (ft_puthexa(va_arg(args, unsigned int), 1));
	if (c == 'u')
		return (ft_putnbr(va_arg(args, unsigned int)));
	if (c == '%')
		return (ft_putstr("%"));
	ft_putchar('%');
	ft_putchar(c);
	return (2);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			count += ft_convert(s[i + 1], args);
			i++;
		}
		else
			ft_putchar(s[i]);
			count++;
		i++;
	}
}
