/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 13:11:31 by dongguki          #+#    #+#             */
/*   Updated: 2020/12/04 20:07:07 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*ans;
	size_t	i;
	int		j;

	i = n < 0 ? 2 : 1;
	j = n;
	while (n /= 10)
		i++;
	if (!(ans = ft_calloc(i + 1, 1)))
		return (0);
	ans[0] = j < 0 ? '-' : '0';
	while (j)
	{
		n = j % 10;
		ans[--i] = '0' + (n < 0 ? -n : n);
		j /= 10;
	}
	return (ans);
}
