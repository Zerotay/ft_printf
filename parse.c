#include "ft_printf.h"

int 	checkflag(const char *s, int *i)
{
	if (s[*i] == '-')
	{
		(*i)++;
		return (1);
	}
	else if (s[*i] == '0')
	{
		(*i)++;
		return (2);
	}
	return (0);
}

int		skipnum(const char *s)
{
	int	i;

	i = 0;
	while ((s[i] >= '0') && (s[i] <= '9'))
		i++;
	return (i);
}

char	checkspec(const char *s, int i)
{
	if ((s[i] == 'd') || (s[i] == 'i') || (s[i] == 'x') ||
		(s[i] == 'X') || (s[i] == 'c') || (s[i] == 's') ||
		(s[i] == 'p') || (s[i] == '%') || (s[i] == 'u'))
		return (s[i]);
	return (0);
}

t_cfc	makecfc(const char *s, int *i, t_cfc cfc, va_list ap)
{
	//만약 예외 처리를 하고 싶다면 여기에서 해야 함
	(*i)++;
	cfc.sort1zero2 = checkflag(s, i);
	if ((cfc.width = ft_atoi(s + *i))) //만약 *와 숫자 나오는 거 고려? 순서 바꿔서
		*i += skipnum(s + *i);
	else if (s[*i] == '*')
	{
		if ((cfc.width = va_arg(ap, int)) < 0)
		{
			cfc.width *= -1;
			cfc.sort1zero2 = 1;
		}
		(*i)++;
	}
	if (s[*i] == '.')
	{
		(*i)++;
		if ((cfc.precision = ft_atoi(s + *i)) || (s[*i] == '0'))
			*i += skipnum(s + *i);
		else if (s[*i] == '*')
		{
			cfc.precision = va_arg(ap, int);
			(*i)++;
		}
		cfc.onlyfors = 1;
	}
	cfc.spec = checkspec(s, *i);
	return (cfc);
}