/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgolbert <wgolbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 15:09:15 by wgolbert          #+#    #+#             */
/*   Updated: 2026/06/29 13:16:29 by wgolbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar_fd(char c)
{
	write (1, &c, sizeof(char));
}

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		ft_putchar_fd(str[count]);
		count++;
	}
	return (count);
}
