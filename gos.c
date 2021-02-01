/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:04:36 by dongguki          #+#    #+#             */
/*   Updated: 2021/02/01 13:04:36 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	sorts(t_cfc cfc, char *val, int len)
{
	char	*buf;
	
	if (!(buf = ft_calloc(cfc.width + 1, 1)))
		return (-1);
	ft_memset(buf, ' ', cfc.width);
	ft_strlcpy(buf, val, len + 1);
	buf[len] = ' ';
	write(1, buf, ft_strlen(buf));
	free(buf);
	return (cfc.width);
}

static int	basic(t_cfc cfc, char *val, int len)
{
	char	*buf;

	if (!(buf = ft_calloc(cfc.width + 1, 1)))
		return (-1);
	ft_memset(buf, ' ', cfc.width);
	ft_strlcpy(buf + (cfc.width - len), val, len + 1);
	write(1, buf, ft_strlen(buf));
	free(buf);
	return (cfc.width);
}

static int	onlyfornulls(t_cfc cfc)
{
	char	*buf;

	if ((cfc.precision > 6 || cfc.precision < 0) || !cfc.onlyfors)
		if (cfc.width > 6)
		{
			if (!(buf = ft_calloc(cfc.width + 1, 1)))
				return (-1);
			ft_memset(buf, ' ', cfc.width);
			ft_strlcpy(buf + (cfc.sort1zero2 == 1 ? 0 : cfc.width - 6), "(null)", 7);
			buf[6] = cfc.sort1zero2 == 1 ? ' ' : buf[6];
			write(1, buf, ft_strlen(buf));
			free(buf);
			return (cfc.width);
		}
		else
			return (write(1, "(null)", 6));
	else
	{
		if (!(buf = ft_calloc(cfc.width + 1, 1)))
			return (-1);
		ft_memset(buf, ' ', cfc.width);
		write(1, buf, ft_strlen(buf));
		free(buf);
		return (cfc.width);
	}
}

int			gos(t_cfc cfc, va_list ap)
{
	char	*val;
	int		len;

	val = va_arg(ap, char *);
	if (!val)
		return (onlyfornulls(cfc));
	cfc.onlyfors = cfc.precision < 0 ? 0 : cfc.onlyfors;
	len = cfc.precision < (int)ft_strlen(val) ? cfc.precision : (int)ft_strlen(val);
	if (cfc.onlyfors)
		if (cfc.width <= len)
			return (write(1, val, len));
		else
			if (cfc.sort1zero2 == 1)
				return (sorts(cfc, val, len));
			else
				return (basic(cfc, val, len));		
	else
		if (cfc.width <= (int)ft_strlen(val))
			return (write(1, val, ft_strlen(val)));
		else
			if (cfc.sort1zero2 == 1)
				return (sorts(cfc, val, ft_strlen(val)));
			else
				return (basic(cfc, val, ft_strlen(val)));
}