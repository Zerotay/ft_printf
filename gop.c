/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:07:28 by dongguki          #+#    #+#             */
/*   Updated: 2021/02/01 19:55:19 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	sortp(t_cfc cfc, unsigned long val, int len)
{
	char	*buf;
	char	*temp;

	if (!(buf = ft_calloc(cfc.width + 1, 1)))
		return (-1);
	if (!(temp = itop(val)))
		return (-1);
	ft_memset(buf, ' ', cfc.width);
	ft_strlcpy(buf, temp, len + 1);
	buf[len] = ' ';
	buf[cfc.width] = 0;
	write(1, buf, ft_strlen(buf));
	free(buf);
	free(temp);
	return (cfc.width);
}

static int	basic(t_cfc cfc, unsigned long val, int len)
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

int			onlyfornil(t_cfc cfc)
{
	char	*buf;

	if (cfc.width > 3)
	{
		if (!(buf = ft_calloc(cfc.width + 1, 1)))
			return (-1);
		ft_memset(buf, ' ', cfc.width);
		ft_strlcpy(buf + (cfc.sort1zero2 == 1 ? 0 : cfc.width - 3), "0x0", 4);
		buf[3] = cfc.sort1zero2 == 1 ? ' ' : buf[3];
		write(1, buf, ft_strlen(buf));
		free(buf);
		return (cfc.width);
	}
	else
		return (write(1, "0x0", 3));
}

// static int	onlyfornulp(t_cfc cfc)
// {
// 	char	*buf;
// 	int		i;

// 	i = cfc.sort1zero2 == 1 ? 0 : cfc.width - 6;
// 	if (cfc.width > 6)
// 	{
// 		if (!(buf = ft_calloc(cfc.width + 1, 1)))
// 			return (-1);
// 		ft_memset(buf, ' ', cfc.width);
// 		ft_strlcpy(buf + i, "(null)", 7);
// 		buf[6] = cfc.sort1zero2 == 1 ? ' ' : buf[6];
// 		write(1, buf, ft_strlen(buf));
// 		free(buf);
// 		return (cfc.width);
// 	}
// 	else
// 		return (write(1, "(null)", 6));
// }

int			gop(t_cfc cfc, va_list ap)
{
	unsigned long	val;
	int				len;

	val = (unsigned long)va_arg(ap, void *);
	// if (!val && !cfc.precision)
	// 	return (onlyfornulp(cfc));
	if (!val)
		return (onlyfornil(cfc));
	len = lengthplus(cfc, val) + 2;
	if (cfc.width <= len)
		return (justwrite(cfc, val));
	else if (cfc.sort1zero2 == 1)
		return (sortp(cfc, val, len));
	else
		return (basic(cfc, val, len));
}
