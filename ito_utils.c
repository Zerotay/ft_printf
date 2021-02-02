/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ito_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 01:23:19 by dongguki          #+#    #+#             */
/*   Updated: 2021/02/02 16:13:04 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*itop(unsigned long n)
{
	char			*ans;
	size_t			i;
	unsigned long	j;

	i = 3;
	j = n;
	while (n /= 16)
		i++;
	if (!(ans = ft_calloc((i + 1), 1)))
		return (0);
	ans[2] = '0';
	while (j)
	{
		n = j % 16;
		if (n > 9)
			ans[--i] = 'a' + (n - 10);
		else
			ans[--i] = '0' + n;
		j /= 16;
	}
	ans[0] = '0';
	ans[1] = 'x';
	return (ans);
}

char	*itoplus(t_cfc cfc, unsigned int n)
{
	char			*ans;
	size_t			i;
	unsigned int	j;
	int				base;

	i = 1;
	j = n;
	base = cfc.spec == 'u' ? 10 : 16;
	while (n /= base)
		i++;
	if (!(ans = ft_calloc((i + 1), 1)))
		return (0);
	ans[0] = '0';
	while (j)
	{
		n = j % base;
		if (n > 9)
			ans[--i] = (cfc.spec == 'X' ? 'A' : 'a') + (n - 10);
		else
			ans[--i] = '0' + n;
		j /= base;
	}
	return (ans);
}

char	*checkito(t_cfc cfc, int val)
{
	char	*ret;

	if (cfc.spec == 'i' || cfc.spec == 'd')
	{
		if (!(ret = ft_itoa(val)))
			return (0);
		return (ret);
	}
	else
	{
		if (!(ret = itoplus(cfc, val)))
			return (0);
		return (ret);
	}
}
