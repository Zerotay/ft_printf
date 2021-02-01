/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_for_num1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 11:49:35 by dongguki          #+#    #+#             */
/*   Updated: 2021/02/01 11:49:35 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		onlyfornull(t_cfc cfc)
{
	char *buf;

	if (!(buf = ft_calloc(cfc.width + 1, 1)))
		return (0);
	ft_memset(buf, ' ', cfc.width);
	write(1, buf, cfc.width);
	free(buf);
	return (cfc.width);
}

int		justwrite(t_cfc cfc, unsigned long val)
{
	char	*buf;
	int		i;

	if (cfc.spec == 'd' || cfc.spec == 'i')
		if (!(buf = ft_itoa(val)))
			return (-1);
	if (cfc.spec == 'u' || cfc.spec == 'x' || cfc.spec == 'X')
		if (!(buf = itoplus(cfc, val)))
			return (-1);
	if (cfc.spec == 'p')
		if (!(buf = itop(val)))
			return (-1);
	i = write(1, buf, ft_strlen(buf));
	free(buf);
	return (i);
}
