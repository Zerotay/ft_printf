/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 15:31:59 by dongguki          #+#    #+#             */
/*   Updated: 2020/12/04 20:11:09 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		recur(int num, int fd)
{
	char		i;

	if (!num)
		return ;
	i = '0' + num % 10;
	num /= 10;
	recur(num, fd);
	ft_putchar_fd(i, fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	else if (n == 0)
	{
		ft_putchar_fd('0', fd);
	}
	else if (n < 0)
	{
		n *= -1;
		ft_putchar_fd('-', fd);
	}
	recur(n, fd);
}
