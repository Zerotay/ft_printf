/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:45:03 by dongguki          #+#    #+#             */
/*   Updated: 2021/02/01 15:45:03 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		checkflag(const char *s, int *i)
{
	int	forzero;
	int	forsort;

	forzero = 0;
	forsort = 0;
	while (s[*i] == '-' || s[*i] == '0')
		if (s[(*i)++] == '-')
			forsort = 1;
		else
			forzero = 2;
	if (forsort)
		return (forsort);
	if (forzero)
		return (forzero);
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
	(*i)++;
	cfc.sort1zero2 = checkflag(s, i);
	if ((cfc.width = ft_atoi(s + *i)))
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
