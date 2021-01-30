/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:35:26 by dongguki          #+#    #+#             */
/*   Updated: 2020/12/04 20:50:00 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;
	t_list	*currnext;

	if (!del || !(*lst))
		return ;
	curr = *lst;
	while (curr)
	{
		currnext = curr->next;
		del(curr->content);
		free(curr);
		curr = currnext;
	}
	*lst = 0;
}
