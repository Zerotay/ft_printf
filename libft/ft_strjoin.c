/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 12:08:01 by dongguki          #+#    #+#             */
/*   Updated: 2020/12/04 19:36:27 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ans;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (!(ans = (char *)malloc(sizeof(char) * (i + j + 1))))
		return (0);
	ft_strlcpy(ans, s1, i + 1);
	ft_strlcpy((ans + i), s2, j + 1);
	if ((!*s1 && !*s2) || (!s1 && !s2))
		ans[0] = 0;
	return (ans);
}
