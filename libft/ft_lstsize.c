/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 17:53:48 by dongguki          #+#    #+#             */
/*   Updated: 2020/12/04 20:26:38 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*cur;

	i = 0;
	if (!lst)
		return (0);
	cur = lst->next;
	i++;
	while (cur)
	{
		cur = cur->next;
		i++;
	}
	return (i);
}
