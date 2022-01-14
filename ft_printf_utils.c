/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 20:44:00 by laubrey           #+#    #+#             */
/*   Updated: 2021/08/09 20:44:11 by laubrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char putin)
{
	write (1, &putin, 1);
	return (1);
}

int	ft_putstr(char *putin)
{
	int		vor;

	vor = 0;
	if (!putin)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (putin[vor])
	{
		ft_putchar(putin[vor]);
		vor++;
	}
	return (vor);
}

int	ft_putnbr(int putin)
{
	int	i;

	i = 0;
	if (putin == -2147483648)
	{
		i = i + ft_putstr("-2147483648");
		return (i);
	}
	else if (putin == 0)
		i = i + ft_putchar('0');
	else
	{
		if (putin < 0)
		{
			putin = putin * -1;
			i = i + ft_putchar('-');
		}
		if (putin > 9)
			i = i + ft_putnbr(putin / 10);
		i = i + ft_putchar(putin % 10 + '0');
	}
	return (i);
}

int	ft_putnbr_h(unsigned long long putin, char x)
{
	int	i;

	i = 0;
	if (putin > 15)
		i = i + ft_putnbr_h(putin / 16, x);
	putin = putin % 16;
	if (putin < 10)
		i = i + ft_putchar(putin + '0');
	else if (x == 'x')
		i = i + ft_putchar(putin % 10 + 'a');
	else if (x == 'X')
		i = i + ft_putchar(putin % 10 + 'A');
	return (i);
}

int	mini(unsigned int putin)
{
	int	i;

	i = 0;
	if (putin > 9)
		i = i + mini(putin / 10);
	i = i + ft_putchar(putin % 10 + '0');
	return (i);
}
