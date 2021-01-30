/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 16:09:40 by dongguki          #+#    #+#             */
/*   Updated: 2020/12/07 00:05:50 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = ft_strlen(dst);
	j = ft_strlen(src);
	if (i > 0 && dstsize <= i)
		return (dstsize + j);
	k = 0;
	while (src[k] && i + k + 1 < dstsize)
	{
		dst[i + k] = src[k];
		k++;
	}
	dst[i + k] = 0;
	return (i + j);
}
