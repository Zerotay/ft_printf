/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 15:46:43 by dongguki          #+#    #+#             */
/*   Updated: 2020/12/04 20:22:33 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*fts1;
	unsigned char	*fts2;
	size_t			i;

	if (!s1 && !s2)
		return (0);
	fts1 = (unsigned char *)s1;
	fts2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (fts1[i] != fts2[i])
			return ((int)(fts1[i] - fts2[i]));
		i++;
	}
	return (0);
}
