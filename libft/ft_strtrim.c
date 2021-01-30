/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 12:08:14 by dongguki          #+#    #+#             */
/*   Updated: 2020/12/04 21:27:41 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		isset(char const s, char const *set)
{
	size_t		i;

	i = -1;
	while (set[++i])
		if (set[i] == s)
			return (1);
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	size_t		j;

	if (!s1)
		return (0);
	i = 0;
	while (isset(s1[i], set))
		i++;
	j = i;
	i = ft_strlen(s1) - 1;
	while (isset(s1[i], set) && i > j)
		i--;
	return (ft_substr(s1, j, i - j + 1));
}
