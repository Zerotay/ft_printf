/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:54:40 by dongguki          #+#    #+#             */
/*   Updated: 2020/11/28 16:37:06 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = ft_strlen(needle);
	k = ft_strlen(haystack);
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i] && len - i >= j && k - i >= j)
	{
		if ((ft_strncmp((haystack + i), needle, j) == 0))
			return ((char *)(haystack + i));
		i++;
	}
	return (0);
}
