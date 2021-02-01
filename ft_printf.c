/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 14:30:04 by dongguki          #+#    #+#             */
/*   Updated: 2021/01/30 14:30:04 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_cfc	zeroinit(t_cfc cfc)
{
	cfc.sort1zero2 = 0;
	cfc.width = 0;
	cfc.precision = 1;
	cfc.onlyfors = 0;
	cfc.spec = 0;
	return (cfc);
}

int	ft_printf(const char *s, ...)
{
	int		ret;
	t_cfc	cfc;
	va_list	ap;
	int		i;
	int		err;

	ret = 0;
	i = -1;
	va_start(ap, s);
	while (s[++i])
	{
		if (s[i] == '%')
		{
			cfc = zeroinit(cfc);
			cfc = makecfc(s, &i, cfc, ap);
			if ((err = print(cfc, ap)) < 0)
				return (-1);
			ret += err;
			continue;
		}
		write(1, &s[i], 1);
		ret++;
	}
	va_end(ap);
	return (ret);
}