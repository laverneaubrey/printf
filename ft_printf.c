/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 20:42:20 by laubrey           #+#    #+#             */
/*   Updated: 2021/08/09 20:42:37 by laubrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parser(char navalny, va_list ap, int i)
{
	if (navalny == 'c')
		i = i + ft_putchar(va_arg(ap, int));
	else if (navalny == 's')
		i = i + ft_putstr(va_arg(ap, char *));
	else if (navalny == 'p')
	{
		i = i + ft_putstr("0x");
		i = i + ft_putnbr_h(va_arg(ap, unsigned long), 'x');
	}
	else if (navalny == 'd')
		i = i + ft_putnbr(va_arg(ap, int));
	else if (navalny == 'i')
		i = i + ft_putnbr(va_arg(ap, int));
	else if (navalny == 'u')
		i = i + mini(va_arg(ap, unsigned int));
	else if (navalny == 'x')
		i = i + ft_putnbr_h(va_arg(ap, unsigned int), 'x');
	else if (navalny == 'X')
		i = i + ft_putnbr_h(va_arg(ap, unsigned int), 'X');
	else if (navalny == '%')
		i = i + ft_putchar('%');
	return (i);
}

int	ft_printf(const char *navalny, ...)
{
	int			i;
	int			char_count;
	int			svobodu;
	va_list		ap;

	i = 0;
	char_count = 0;
	va_start(ap, navalny);
	svobodu = 0;
	while (navalny[svobodu] != '\0')
	{
		if (navalny[svobodu] == '%')
			char_count = char_count + parser(navalny[++svobodu], ap, i);
		else
			char_count = char_count + ft_putchar(navalny[svobodu]);
		svobodu++;
		i = 0;
	}
	va_end(ap);
	return (char_count);
}
