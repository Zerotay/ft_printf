/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 19:05:48 by dongguki          #+#    #+#             */
/*   Updated: 2020/12/06 22:22:19 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_isspace(char c)
{
	return ((c == '\n') || (c == '\v') ||
			(c == '\t') || (c == '\f') ||
			(c == ' ') || (c == '\r'));
}

static void			ft_pass(const char *str, size_t *i, int *sign)
{
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign *= -1;
		(*i)++;
	}
	while (str[*i] == '0')
		(*i)++;
}

int					ft_atoi(const char *str)
{
	size_t				i;
	int					sign;
	unsigned long long	ans;

	i = 0;
	sign = 1;
	ans = 0;
	while (ft_isspace(str[i]))
		i++;
	ft_pass(str, &i, &sign);
	while (str[i] <= '9' && str[i] >= '0')
		ans = ans * 10 + (str[i++] - '0');
	if (sign == 1 && ans > 2147483647)
		return (-1);
	if (sign == -1 && ans > 2147483648)
		return (0);
	return (sign * ans);
}
