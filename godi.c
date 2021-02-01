/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   godi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:00:34 by dongguki          #+#    #+#             */
/*   Updated: 2021/02/01 13:00:34 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		basic(t_cfc cfc, int val, int len)
{
	char	*buf;
	char	*temp;
	int		i;

	i = cfc.precision > len ? cfc.precision : len;
	if (!(buf = ft_calloc(cfc.width + 1, 1)) || !(temp = checkito(cfc, val)))
		return (-1);
	ft_memset(buf, ' ', cfc.width);
	if (cfc.precision >= len)
	{
		ft_memset(buf + cfc.width - cfc.precision, '0', cfc.precision);
		buf[cfc.width - i - 1] = val < 0 ? '-' : buf[cfc.width - i - 1];
	}	
	len = length(val);
	i = cfc.width - len;
	ft_strlcpy(buf + i, temp, len + 1);
	buf[i] = ((val < 0) && (cfc.precision >= len)) ? '0' : buf[i];
	write(1, buf, ft_strlen(buf));
	free(buf);
	free(temp);
	return (cfc.width);
}

int			zero(t_cfc cfc, int val, int len)
{
	char	*buf;
	char	*temp;
	int		i;

	if (cfc.onlyfors && cfc.precision >= 0)
		return (basic(cfc, val, len));
	i = val < 0 ? cfc.width - len + 1 : cfc.width - len;
	if (!(buf = ft_calloc(cfc.width + 1, 1)) || !(temp = ft_itoa(val)))
		return (-1);
	ft_memset(buf, '0', cfc.width);
	buf[0] = val >= 0 ? buf[0] : '-';
	ft_strlcpy(buf + i, (val < 0 ? temp + 1 : temp), len + 1);
	write(1, buf, ft_strlen(buf));
	free(buf);
	free(temp);
	return (cfc.width);
}

int			godi(t_cfc cfc, va_list ap)
{
	int	val;
	int	len;

	val = va_arg(ap, int);
	len = length(val);
	if (!val && !cfc.precision)
		return (onlyfornull(cfc));
	else
		if (cfc.width < len)
			if (cfc.precision >= len)
				return (precisionlong(cfc, val, len));
			else
				return (justwrite(cfc, val));
		else
			if (cfc.precision >= cfc.width)
				return (precisionlong(cfc, val, len));
			else
				if (cfc.sort1zero2 == 1)
					return (sort(cfc, val, len));
				else if (cfc.sort1zero2 == 2)
					return (zero(cfc, val, len));
				else
					return (basic(cfc, val, len));
}