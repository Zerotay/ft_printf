/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 12:08:31 by dongguki          #+#    #+#             */
/*   Updated: 2020/11/22 17:45:42 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*al;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	if (!(al = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	j = ft_strlen(s);
	while (len-- > 0 && j > start)
	{
		al[i] = s[i + start];
		i++;
	}
	al[i] = 0;
	return (al);
}
