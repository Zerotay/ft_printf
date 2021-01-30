/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 15:21:25 by dongguki          #+#    #+#             */
/*   Updated: 2020/12/04 20:37:51 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*fts;
	unsigned char	ftc;
	size_t			i;

	fts = (unsigned char *)s;
	ftc = (unsigned char)c;
	i = -1;
	while (++i < n)
		if (fts[i] == ftc)
			return (fts + i);
	return (0);
}
