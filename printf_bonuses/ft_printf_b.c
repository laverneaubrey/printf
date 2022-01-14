#include "ft_printf.h"

void	ft_putchar(char putin)
{
	write (1, &putin, 1);
}

void	ft_putstr(char *putin)
{
	int	vor;

	vor = 0;
	if (!putin)
	{
		ft_putstr("(null)");
		return ;
	}
	while (putin[vor])
	{
		ft_putchar(putin[vor]);
		vor++;
	}
}

void	ft_putnbr(int putin)
{
	if (putin == -2147483648)
		ft_putstr("-2147483648");
	else if (putin == 0)
		ft_putchar('0');
	else
	{
		if (putin < 0)
		{
			putin = putin * -1;
			ft_putchar('-');
		}
		if (putin > 9)
			ft_putnbr(putin / 10);
		ft_putchar(putin % 10 + '0');
	}
}

void	ft_putnbr_h(long long int putin, char x)
{
		if (putin > 15)
			ft_putnbr_h(putin / 16, x);
		putin = putin % 16;
		if (putin < 10)
			ft_putchar(putin + '0');
		else if (x == 'x')
			ft_putchar(putin % 10 + 'a');
		else if (x == 'X')
			ft_putchar(putin % 10 + 'A');

}

void	mini(unsigned int putin)
{
	if (putin > 9)
		mini(putin / 10);
	ft_putchar(putin % 10 + '0');
}
