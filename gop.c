/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:07:28 by dongguki          #+#    #+#             */
/*   Updated: 2021/02/02 15:55:03 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			precisionlongp(t_cfc cfc, int val, int len)
{
	char	*buf;
	char	*temp;
	int		ret;

	if (!(buf = ft_calloc(cfc.precision + 3, 1)))
		return (-1);
	if (!(temp = itop(val)))
		return (-1);
	ft_memset(buf, '0', cfc.precision);
	ft_strlcpy(buf + (cfc.precision + 2 - len), temp, len + 1);
	// ft_strlcpy(buf + (cfc.precision + 2 - len), temp, len + 1);
	// buf[cfc.precision + 3 - len] = '0';
	buf[0] = '0';
	buf[1] = 'x';
	ret = write(1, buf, ft_strlen(buf));
	free(temp);
	free(buf);
	return (ret);
}

static int	sortp(t_cfc cfc, unsigned long val, int len)
{
	char	*buf;
	char	*temp;
	int		i;

	i = cfc.precision >= len ? cfc.precision - len : 0;
	if (!(buf = ft_calloc(cfc.width + 1, 1)))
		return (-1);
	if (!(temp = itop(val)))
		return (-1);
	if (cfc.precision >= len)
		ft_memset(buf, '0', cfc.width);
	ft_strlcpy(buf + i, temp, len + 1);
	ft_memset(buf, ' ', cfc.width);
	buf[len] = cfc.width == len ? 0 : ' ';
	write(1, buf, ft_strlen(buf));
	free(buf);
	free(temp);
	return (cfc.width);
}

static int	basicp(t_cfc cfc, unsigned long val, int len)
{
	char	*buf;
	char	*temp;

	if (!(buf = ft_calloc(cfc.width + 1, 1)))
		return (-1);
	if (!(temp = itop(val)))
		return (-1);
	ft_memset(buf, ' ', cfc.width);
	ft_strlcpy(buf + (cfc.width - len), temp, len + 1);
	write(1, buf, ft_strlen(buf));
	free(buf);
	free(temp);
	return (cfc.width);
}

static int	zerop(t_cfc cfc, unsigned long val, int len)
{
	char	*buf;
	char	*temp;

	if (cfc.onlyfors && cfc.precision >= 0)
		return (basicp(cfc, val, len));
	if (!(buf = ft_calloc(cfc.width + 1, 1)))
		return (-1);
	if (!(temp = itop(val)))
		return (-1);
	ft_memset(buf, '0', cfc.width);
	ft_strlcpy(buf + (cfc.width - len), temp, len + 1);
	write(1, buf, ft_strlen(buf));
	free(buf);
	free(temp);
	return (cfc.width);
}

int			gop(t_cfc cfc, va_list ap)
{
	long long	val;
	int					len;

	val = (long long)va_arg(ap, void *);
	if (!val && !cfc.onlyfors)
		return (onlyfornul(cfc));
	if (!val)
		return (onlyfornil(cfc));
	len = lengthplus(cfc, val);
	// len = lengthplus(cfc, val) + 2;
	if (cfc.width < len + 2)
		if (cfc.precision >= len)
			return (precisionlongp(cfc, val, len));
		else
			return (justwrite(cfc, val));
	else if (cfc.precision >= cfc.width)
		return (precisionlongp(cfc, val, len));
	else if (cfc.sort1zero2 == 1)
		return (sortp(cfc, val, len));
	else if (cfc.sort1zero2 == 2)
		return (zerop(cfc, val, len));
	else
		return (basicp(cfc, val, len));
}
