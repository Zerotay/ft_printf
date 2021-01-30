/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 14:26:44 by dongguki          #+#    #+#             */
/*   Updated: 2020/12/04 20:13:18 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*ftdest;
	unsigned char		*ftsrc;
	unsigned char		find;
	size_t				i;

	ftdest = (unsigned char *)dest;
	ftsrc = (unsigned char *)src;
	find = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		ftdest[i] = ftsrc[i];
		if (ftsrc[i] == find)
			return (dest + (i + 1));
		i++;
	}
	return (0);
}
