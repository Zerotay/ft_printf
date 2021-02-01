/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gol.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 19:59:47 by dongguki          #+#    #+#             */
/*   Updated: 2021/02/01 20:12:30 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	gol(t_cfc cfc)
{
	char	*buf;

	if (cfc.width < 1)
		return (write(1, "%", 1));
	else
	{
		if (!(buf = ft_calloc(cfc.width + 1, 1)))
			return (-1);
		ft_memset(buf, ' ', cfc.width);
		if (cfc.sort1zero2 == 2)
			ft_memset(buf, '0', cfc.width);
		buf[(cfc.sort1zero2 == 1 ? 0 : cfc.width - 1)] = '%';
		write(1, buf, ft_strlen(buf));
		free(buf);
		return (cfc.width);
	}
}
