/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:03:48 by dongguki          #+#    #+#             */
/*   Updated: 2021/02/02 14:39:33 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	sortc(t_cfc cfc, char val)
{
	char	*buf;
	int		i;

	if (!(buf = ft_calloc(cfc.width + 1, 1)))
		return (-1);
	i = 1;
	while (i < cfc.width)
		buf[i++] = ' ';
	buf[0] = val;
	write(1, buf, ft_strlen(buf));
	free(buf);
	return (cfc.width);
}

static int	basicc(t_cfc cfc, char val)
{
	char	*buf;
	int		i;

	if (!(buf = ft_calloc(cfc.width + 1, 1)))
		return (-1);
	i = 0;
	while (i < cfc.width)
		buf[i++] = ' ';
	buf[i - 1] = val;
	write(1, buf, ft_strlen(buf));
	free(buf);
	return (cfc.width);
}

int			onlyforshit(t_cfc cfc)
{
	char	*buf;

	if (cfc.width > 1)
	{
		if (!(buf = ft_calloc(cfc.width + 1, 1)))
			return (-1);
		ft_memset(buf, ' ', cfc.width);
		buf[(cfc.sort1zero2 == 1 ? 0 : cfc.width - 1)] = '\0';
		write(1, buf, cfc.width);
		free(buf);
		return (cfc.width);
	}
	else
		return (write(1, "\0", 1));
}

int			goc(t_cfc cfc, va_list ap)
{
	char	val;

	val = va_arg(ap, int);
	if (val == '\0')
		return (onlyforshit(cfc));
	else if (cfc.width > 1)
		if (cfc.sort1zero2 == 1)
			return (sortc(cfc, val));
		else
			return (basicc(cfc, val));
	else
		return (write(1, &val, 1));
}
