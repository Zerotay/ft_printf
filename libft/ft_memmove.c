/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 14:46:36 by dongguki          #+#    #+#             */
/*   Updated: 2020/12/04 20:37:39 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ftdst;
	unsigned char	*ftsrc;

	if (dst == src)
		return (dst);
	if (!src && !dst)
		return (dst);
	ftdst = (unsigned char *)dst;
	ftsrc = (unsigned char *)src;
	if (ftdst < ftsrc)
		while (len-- > 0)
			*ftdst++ = *(unsigned char *)src++;
	else
		while (len-- > 0)
			ftdst[len] = ftsrc[len];
	return (dst);
}
