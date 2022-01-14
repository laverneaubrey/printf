/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 20:43:34 by laubrey           #+#    #+#             */
/*   Updated: 2021/08/09 20:43:42 by laubrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_putchar(char putin);
int		ft_putstr(char *putin);
int		ft_putnbr(int putin);
int		ft_putnbr_h(unsigned long long putin, char x);
int		mini(unsigned int putin);
int		parser(char navalny, va_list ap, int i);
int		ft_printf(const char *navalny, ...);

#endif
