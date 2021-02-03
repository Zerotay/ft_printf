/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 14:30:04 by dongguki          #+#    #+#             */
/*   Updated: 2021/02/03 13:55:57 by dongguki         ###   ########.fr       */
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

int		gol(t_cfc cfc)
{
	char	*buf;

	if (cfc.width < 1)
		return (write(1, "%", 1));
	else
	{
		if (!(buf = ft_calloc(cfc.width + 1, 1)))
			return (-1);
		ft_memset(buf, ' ', cfc.width);
		if (cfc.sort1zero2 == 2)
			ft_memset(buf, '0', cfc.width);
		buf[(cfc.sort1zero2 == 1 ? 0 : cfc.width - 1)] = '%';
		write(1, buf, ft_strlen(buf));
		free(buf);
		return (cfc.width);
	}
}

int		print(t_cfc cfc, va_list ap)
{
	if (cfc.spec == 'd' || cfc.spec == 'i')
		return (godi(cfc, ap));
	else if (cfc.spec == 'x' || cfc.spec == 'X' || cfc.spec == 'u')
		return (gox(cfc, ap));
	else if (cfc.spec == 'c')
		return (goc(cfc, ap));
	else if (cfc.spec == 's')
		return (gos(cfc, ap));
	else if (cfc.spec == 'p')
		return (gop(cfc, ap));
	else if (cfc.spec == '%')
		return (gol(cfc));
	return (0);
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
