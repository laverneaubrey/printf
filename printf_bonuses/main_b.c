#include "ft_printf.h"

void	accure_point(char *str,  flags *value)
{
	int i;
	int cou;

	cou = 0;
	i = 1;
	if (str[i] >= 0 && str[i] <= 9)
	{
		cou = str[i];
		while (str[i + 1] >= 0 && str[i + 1] <= 9)
			cou = cou * 10 + str[++i];
	}
	value->accur = cou;
	i = -1;
	cou = 0;
	if (str[i] >= 0 && str[i] <= 9)
	{
		cou = str[i];
		while (str[i - 1] >= 0 && str[i - 1] <= 9)
			cou = cou + str[--i] * 10;
	}
	value->width = cou;
}

void	values_opinion(char *str, flags *value)
{
	int i;
	int cou;

	i = 0;
	while (type_serch(str[i], value))
	{
		if (str[i] != '.')
		{
			if (str[i] == '+')
				value->sign = '+';
			if (str[i] == ' ')
				value->sign = ' ';
			if (str[i] == '#')
				value->hexa = 1;
			if (str[i] == '-')
				value->minus = 1;
		}
		else
			accure_point(&str[i], value);
		i++;
	}
}

int		type_serch(char str,  flags *value)
{
	if (str == 'c')
		value->type = 'c';
	else if (str == 's')
		value->type = 's';
	else if (str == 'p')
		value->type = 'p';
	else if (str == 'd')
		value->type = 'd';
	else if (str == 'i')
		value->type = 'i';
	else if (str == 'u')
		value->type = 'u';
	else if (str == 'x')
		value->type = 'x';
	else if (str == 'X')
		value->type = 'X';
	else if (str == '%')
		value->type = '%';
	else
		return (1);
	return (0);
}

int	ft_printf(const char *navalny, ...)
{
	int		svobodu;
	va_list	ap;
	flags	value;

	va_start(ap, navalny);
	svobodu = 0;
	while (navalny[svobodu] != '\0')
	{
		if (navalny[svobodu] == '%')
		{
			values_opinion(navalny[++svobodu], &value);
			parser(navalny[svobodu], ap);
		}
		else
			ft_putchar(navalny[svobodu]);
		svobodu++;
	}
	va_end(ap);
	return (0);
}

int main()
{
	{
		void*  nb0 = NULL;
		int   nb1 = -2147483648;
		int   nbMin = -214748364;
		int   nbMax = 56;
		char  *test = "Yes, just a test string! Cann\'t imagine it\'s not working4294967295";
		//cspdiuxX%
		ft_printf("=============\n");
		ft_printf("%d\n", nbMin - 1);
		printf("%d\n", nbMin - 1);
		ft_printf("=============\n");
		ft_printf("%d\n", nbMax + 1);
		printf("%d\n", nbMax + 1);
		ft_printf("========check P=====\n");
		ft_printf("%p\n", test);
		printf("%p\n", test);
		ft_printf("=======check P======\n");
		ft_printf("%p\n", &nb0 );
		printf("%p\n", &nb0);
		ft_printf("=======check P======\n");
		ft_printf("%p\n", NULL);
		printf("%p\n", NULL);
		ft_printf("=============\n");
		ft_printf("%c\n", nb1);
		printf("%c\n", nb1);
		ft_printf("=============\n");
		ft_printf("%x|%s|%p|%d|%i\n", nb1, test, &test, nbMin, nbMax);
		printf("%x|%s|%p|%d|%i\n", nb1, test, &test, nbMin, nbMax);
		ft_printf("====================================================\n");
		ft_printf("this %u number\n", 17);
		printf("this %u number\n", 17);
		ft_printf("=============\n");
		ft_printf("%u\n", 4294967295u);
		printf("%u\n", 4294967295u);
		ft_printf("=============\n");
		ft_printf("this %u number\n", 17);
		printf("this %u number\n", 17);
		ft_printf("=============\n");
		ft_printf(" %s \n", "");
		printf(" %s \n", "");
		ft_printf("=============\n");


		return (0);
	}
}