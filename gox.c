/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gox.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:02:37 by dongguki          #+#    #+#             */
/*   Updated: 2021/02/01 13:02:37 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	basic(t_cfc cfc, int val, int len)
{
	char	*buf;
	char	*temp;
	int		i;

	i = 0;
	if (!(buf = (char *)malloc(sizeof(char) * (cfc.width + 1))))
		return (-1);
	buf[cfc.width] = 0;
	if (!(temp = itoplus(cfc, val)))
		return (-1);
	if (cfc.precision >= len)
	{
		while (i < cfc.width - cfc.precision)
			buf[i++] = ' ';
		while (cfc.precision-- - len)
			buf[i++] = '0';
		ft_strlcpy(buf + i, temp, len + 1);
	}
	else
	{
		while (i < cfc.width - len)
			buf[i++] = ' ';
		ft_strlcpy(buf + i, temp, len + 1);
	}
	write(1, buf, ft_strlen(buf));
	free(buf);
	free(temp);
	return (cfc.width);
}

static int	zero(t_cfc cfc, int val, int len)
{
	char	*buf;
	char	*temp;
	int		i;

	if (cfc.onlyfors && cfc.precision >= 0)
		return (basic(cfc, val, len));
	i = 0;
	if (!(buf = (char *)malloc(sizeof(char) * (cfc.width + 1))))
		return (-1);
	buf[cfc.width] = 0;
	if (!(temp = itoplus(cfc, val)))
		return (-1);
	while (i < cfc.width - len)
		buf[i++] = '0';
	ft_strlcpy(buf + i, temp, len + 1);
	write(1, buf, ft_strlen(buf));
	free(buf);
	free(temp);
	return (cfc.width);
}

int			gox(t_cfc cfc, va_list ap)
{
	unsigned int	val;
	int				len;

	val = va_arg(ap, unsigned int);
	len = lengthplus(cfc, val);
	if (!val && !cfc.precision)
		return (onlyfornull(cfc));
	else if (cfc.width < len)
		if (cfc.precision >= len)
			return (precisionlong(cfc, val, len));
		else
			return (justwrite(cfc, val));
	else if (cfc.precision >= cfc.width)
		return (precisionlong(cfc, val, len));
	else if (cfc.sort1zero2 == 1)
		return (sort(cfc, val, len));
	else if (cfc.sort1zero2 == 2)
		return (zero(cfc, val, len));
	else
		return (basic(cfc, val, len));
}
