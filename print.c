/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:09:46 by dongguki          #+#    #+#             */
/*   Updated: 2021/02/01 14:09:46 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print(t_cfc cfc, va_list ap)
{
	if (cfc.spec == 'd' || cfc.spec == 'i')
		return (godi(cfc, ap));
	else if (cfc.spec == 'x')
		return (gox(cfc, ap));
	else if (cfc.spec == 'X')
		return (goxx(cfc, ap));
	else if (cfc.spec == 'u')
		return (gou(cfc, ap));
	else if (cfc.spec == 'c')
		return (goc(cfc, ap));
	else if (cfc.spec == 's')
		return (gos(cfc, ap));
	else if (cfc.spec == 'p')
		return (gop(cfc, ap));
	else if (cfc.spec == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}