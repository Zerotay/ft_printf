/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 12:11:09 by dongguki          #+#    #+#             */
/*   Updated: 2021/02/01 14:13:55 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count(char const *s, char c)
{
	size_t		i;
	size_t		j;

	j = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			continue;
		}
		while (s[i] != c && s[i])
			i++;
		j++;
	}
	return (j);
}

static void		stop(char **ans, size_t i)
{
	size_t j;

	j = -1;
	while (++j < i)
		free(ans[j]);
	free(ans);
}

static char		**make(char const *s, char c, char **ans, size_t wc)
{
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	j = 0;
	while (i < wc && s[j])
	{
		k = 0;
		while (s[j] == c && s[j])
			j++;
		while (s[j + k] != c && s[j + k])
			k++;
		ans[i] = ft_substr(s, j, k);
		if (!ans[i])
		{
			stop(ans, i);
			return (0);
		}
		i++;
		j += k;
	}
	ans[i] = 0;
	return (ans);
}

char			**ft_split(char const *s, char c)
{
	char		**ans;
	size_t		i;

	if (!s)
		return (0);
	i = count(s, c);
	if (!(ans = (char**)malloc(sizeof(char*) * (i + 1))))
		return (0);
	if (!make(s, c, ans, i))
		return (0);
	return (ans);
}
