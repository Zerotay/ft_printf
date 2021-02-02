/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   godi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:00:34 by dongguki          #+#    #+#             */
/*   Updated: 2021/02/02 14:39:32 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		precisionlongdi(t_cfc cfc, int val, int len)
{
	char	*buf;
	char	*temp;
	int		i;
	int		ret;

	i = 0;
	if (!(buf = ft_calloc(cfc.precision + 1, 1)))
		return (-1);
	if (!(temp = checkito(cfc, val)))
		return (-1);
	if (val < 0)
		buf[i++] = '-';
	while (cfc.precision-- - len)
		buf[i++] = '0';
	ft_strlcpy(buf + i, temp, len + 1);
	buf[i] = val < 0 ? '0' : buf[i];
	ret = write(1, buf, ft_strlen(buf));
	free(temp);
	free(buf);
	return (ret);
}

int		sortdi(t_cfc cfc, int val, int len)
{
	char	*buf;
	char	*temp;
	int		i;

	i = cfc.precision >= len ? cfc.precision - len : 0;
	i = (cfc.precision >= len && val < 0) ? i + 1 : i;
	if (!(buf = ft_calloc(cfc.width + 1, 1)))
		return (-1);
	if (!(temp = checkito(cfc, val)))
		return (-1);
	if (cfc.precision >= len)
		ft_memset(buf, '0', cfc.width);
	ft_strlcpy(buf + i, temp, len + 1);
	buf[i] = ((val < 0) && (cfc.precision >= len)) ? '0' : buf[i];
	i = cfc.precision >= len ? cfc.precision : len;
	i = ((i == cfc.precision) && (val < 0)) ? i + 1 : i;
	ft_memset(buf + i, ' ', cfc.width - i);
	buf[0] = val < 0 ? '-' : buf[0];
	write(1, buf, ft_strlen(buf));
	free(buf);
	free(temp);
	return (cfc.width);
}

int		basicdi(t_cfc cfc, int val, int len)
{
	char	*buf;
	char	*temp;
	int		i;

	i = cfc.precision > len ? cfc.precision : len;
	if (!(buf = ft_calloc(cfc.width + 1, 1)))
		return (-1);
	if (!(temp = checkito(cfc, val)))
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

int		zerodi(t_cfc cfc, int val, int len)
{
	char	*buf;
	char	*temp;
	int		i;

	if (cfc.onlyfors && cfc.precision >= 0)
		return (basicdi(cfc, val, len));
	i = val < 0 ? cfc.width - len + 1 : cfc.width - len;
	if (!(buf = ft_calloc(cfc.width + 1, 1)))
		return (-1);
	if (!(temp = ft_itoa(val)))
		return (-1);
	ft_memset(buf, '0', cfc.width);
	buf[0] = val >= 0 ? buf[0] : '-';
	ft_strlcpy(buf + i, (val < 0 ? temp + 1 : temp), len + 1);
	write(1, buf, ft_strlen(buf));
	free(buf);
	free(temp);
	return (cfc.width);
}

int		godi(t_cfc cfc, va_list ap)
{
	int	val;
	int	len;

	val = va_arg(ap, int);
	len = length(val);
	if (!val && !cfc.precision)
		return (onlyfornull(cfc));
	else if (cfc.width < len)
		if (cfc.precision >= len)
			return (precisionlongdi(cfc, val, len));
		else
			return (justwrite(cfc, val));
	else if (cfc.precision >= cfc.width)
		return (precisionlongdi(cfc, val, len));
	else if (cfc.sort1zero2 == 1)
		return (sortdi(cfc, val, len));
	else if (cfc.sort1zero2 == 2)
		return (zerodi(cfc, val, len));
	else
		return (basicdi(cfc, val, len));
}
