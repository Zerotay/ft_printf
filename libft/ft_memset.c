/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 14:24:40 by dongguki          #+#    #+#             */
/*   Updated: 2020/12/04 20:24:58 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	ftc;
	unsigned char	*ftb;

	ftc = (unsigned char)c;
	ftb = (unsigned char*)b;
	while (len-- > 0)
		*ftb++ = ftc;
	return (b);
}
