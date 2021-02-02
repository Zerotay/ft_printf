/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onlyforp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 12:24:23 by dongguki          #+#    #+#             */
/*   Updated: 2021/02/02 14:39:30 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			onlyfornul(t_cfc cfc)
{
	char	*buf;

	if (cfc.width <= 3)
		return (write(1, "0x0", 3));
	if (!(buf = ft_calloc(cfc.width + 1, 1)))
		return (-1);
	ft_memset(buf, ' ', cfc.width);
	ft_strlcpy(buf + (cfc.sort1zero2 == 1 ? 0 : cfc.width - 3), "0x0", 4);
	buf[3] = (cfc.sort1zero2 == 1 && cfc.width != 3) ? ' ' : buf[3];
	write(1, buf, ft_strlen(buf));
	free(buf);
	return (cfc.width);
}

int			onlyfornil(t_cfc cfc)
{
	char	*buf;

	if (cfc.precision >= cfc.width)
	{
		if (!(buf = ft_calloc(cfc.precision + 3, 1)))
			return (-1);
		ft_memset(buf, '0', cfc.precision + 2);
		buf[1] = 'x';
		write(1, buf, ft_strlen(buf));
		free(buf);
		return (cfc.precision + 2);
	}
	else
	{
		if (cfc.width < 2)
			return (write(1, "0x", 2));
		if (!(buf = ft_calloc(cfc.width + 1, 1)))
			return (-1);
		ft_memset(buf, ' ', cfc.width);
		buf[(cfc.sort1zero2 == 1 ? 0 : cfc.width - 2)] = '0';
		buf[(cfc.sort1zero2 == 1 ? 1 : cfc.width - 1)] = 'x';
		write(1, buf, ft_strlen(buf));
		free(buf);
		return (cfc.width);
	}
}
