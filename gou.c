/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gou.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:01:46 by dongguki          #+#    #+#             */
/*   Updated: 2021/02/02 14:39:18 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			gou(t_cfc cfc, va_list ap)
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
