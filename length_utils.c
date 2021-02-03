/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 01:44:21 by dongguki          #+#    #+#             */
/*   Updated: 2021/02/03 13:57:03 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	lengthplus(t_cfc cfc, unsigned long val)
{
	int	i;

	if (val == 0)
		return (1);
	i = 0;
	while (val)
	{
		i++;
		val /= (cfc.spec == 'u' ? 10 : 16);
	}
	return (i);
}

int	length(int val)
{
	int	i;

	if (val == 0)
		return (1);
	i = val < 0 ? 1 : 0;
	while (val)
	{
		i++;
		val /= 10;
	}
	return (i);
}
