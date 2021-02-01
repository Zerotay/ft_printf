/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_for_num2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:52:02 by dongguki          #+#    #+#             */
/*   Updated: 2021/02/01 12:52:02 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		precisionlong(t_cfc cfc, int val, int len)
{
	char	*buf;
	char	*temp;
	int		i;
	int		ret;

	i = 0;
	if (!(buf = ft_calloc(cfc.precision + 1,1)) || !(temp = checkito(cfc, val)))
		return (-1);
	buf[cfc.precision] = 0;
	if (val < 0)
		buf[i++] = '-';
	while (cfc.precision-- - len)
		buf[i++] = '0';
	ft_strlcpy(buf + i, temp, len + 1);
	buf[i] = val < 0 ? '0' : buf[i];
	ret = write(1, buf, ft_strlen(buf));
	free(temp);
	free(buf);
	return (ret);
}

int		sort(t_cfc cfc, int val, int len)
{
	char	*buf;
	char	*temp;
	int		i;

	i = cfc.precision >= len ? cfc.precision - len : 0;
	i = (cfc.precision >= len && val < 0) ? i + 1 : i;
	if (!(buf = ft_calloc(cfc.width + 1, 1)) || !(temp = checkito(cfc, val)))
		return (-1);
	if (cfc.precision >= len)
		ft_memset(buf, '0', cfc.width);
	ft_strlcpy(buf + i, temp, len + 1);
	buf[i] = ((val < 0) && (cfc.precision >= len)) ? '0' : buf[i];
	i = cfc.precision >= len ? cfc.precision : len;
	i = ((i == cfc.precision) && (val < 0)) ? i + 1 : i;
	ft_memset(buf + i, ' ', cfc.width - i);
	buf[0] = val < 0 ? '-' : buf[0];
	write(1, buf, ft_strlen(buf));
	free(buf);
	free(temp);	
	return (cfc.width);
}
