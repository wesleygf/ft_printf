/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgolbert <wgolbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 15:10:50 by wgolbert          #+#    #+#             */
/*   Updated: 2026/06/28 15:49:52 by wgolbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static char	itoh(int n)
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

static char	*ft_converthexa(int n)
{
	char	*converted;
	int		i;
	int		t;

	i = n;
	t = 0;
	converted = malloc(7050);
	while (i > 0)
	{
		*converted = itoh (i % 16);
		i = i / 16;
	}
	return (converted);
}
int ft_puthexa()
{
	
}