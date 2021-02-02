/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_for_num2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:52:02 by dongguki          #+#    #+#             */
/*   Updated: 2021/02/02 16:01:29 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	precisionlong(t_cfc cfc, int val, int len)
{
	char	*buf;
	char	*temp;
	int		i;
	int		ret;

	i = 0;
	if (!(buf = ft_calloc(cfc.precision + 1, 1)))
		return (-1);
	if (!(temp = checkito(cfc, val)))
		return (-1);
	while (cfc.precision-- - len)
		buf[i++] = '0';
	ft_strlcpy(buf + i, temp, len + 1);
	ret = write(1, buf, ft_strlen(buf));
	free(temp);
	free(buf);
	return (ret);
}

int	sort(t_cfc cfc, int val, int len)
{
	char	*buf;
	char	*temp;
	int		i;

	i = cfc.precision >= len ? cfc.precision - len : 0;
	if (!(buf = ft_calloc(cfc.width + 1, 1)))
		return (-1);
	if (!(temp = checkito(cfc, val)))
		return (-1);
	if (cfc.precision >= len)
		ft_memset(buf, '0', cfc.width);
	ft_strlcpy(buf + i, temp, len + 1);
	i = cfc.precision >= len ? cfc.precision : len;
	ft_memset(buf + i, ' ', cfc.width - i);
	write(1, buf, ft_strlen(buf));
	free(buf);
	free(temp);
	return (cfc.width);
}

int	basic(t_cfc cfc, int val, int len)
{
	char	*buf;
	char	*temp;
	int		i;

	i = 0;
	if (!(buf = ft_calloc(cfc.width + 1, 1)))
		return (-1);
	if (!(temp = checkito(cfc, val)))
		return (-1);
	ft_memset(buf, ' ', cfc.width);
	if (cfc.precision >= len)
		ft_memset(buf + cfc.width - cfc.precision, '0', cfc.precision);
	i = cfc.width - len;
	ft_strlcpy(buf + i, temp, len + 1);
	write(1, buf, ft_strlen(buf));
	free(buf);
	free(temp);
	return (cfc.width);
}

int	zero(t_cfc cfc, int val, int len)
{
	char	*buf;
	char	*temp;
	int		i;

	if (cfc.onlyfors && cfc.precision >= 0)
		return (basic(cfc, val, len));
	i = 0;
	if (!(buf = ft_calloc(cfc.width + 1, 1)))
		return (-1);
	if (!(temp = checkito(cfc, val)))
		return (-1);
	while (i < cfc.width - len)
		buf[i++] = '0';
	ft_strlcpy(buf + i, temp, len + 1);
	write(1, buf, ft_strlen(buf));
	free(buf);
	free(temp);
	return (cfc.width);
}
