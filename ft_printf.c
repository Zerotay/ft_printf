/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 14:30:04 by dongguki          #+#    #+#             */
/*   Updated: 2021/02/02 14:39:34 by dongguki         ###   ########.fr       */
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

int		ft_vprintf(const char *s, va_list ap)
{
	t_cfc	cfc;
	int		i;
	int		err;
	int		ret;

	i = -1;
	ret = 0;
	while (s[++i])
	{
		if (s[i] == '%')
		{
			cfc = zeroinit(cfc);
			cfc = makecfc(s, &i, cfc, ap);
			if ((err = print(cfc, ap)) < 0)
				return (-1);
			ret += err;
			if (!s[i])
				return (0);
			continue;
		}
		write(1, &s[i], 1);
		ret++;
	}
	return (ret);
}

int		ft_printf(const char *s, ...)
{
	int		ret;
	va_list	ap;

	va_start(ap, s);
	ret = ft_vprintf(s, ap);
	va_end(ap);
	return (ret);
}
