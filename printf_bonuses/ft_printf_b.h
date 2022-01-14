#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_flags
{
	char 	type = 0;
	int		width = 0;
	int 	accur = -1;
	char 	zero = ' ';
	char	sign = 0;
	int 	hexa = 0;
	int	minus = 0;
}				flags;

void	ft_putchar(char putin);
void	ft_putstr(char *putin);
void	ft_putnbr(int putin);
void	ft_putnbr_h(long long int putin, char x);
void	mini(unsigned int putin);
void	parser(char navalny, va_list ap);
int		ft_printf(const char *navalny, ...);

#endif
