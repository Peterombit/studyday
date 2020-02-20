/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdelsie <vdelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 13:18:51 by nmei              #+#    #+#             */
/*   Updated: 2019/12/14 19:24:25 by vdelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*new_start;
	t_list	*tmp;

	new = NULL;
	tmp = (*f)(lst);
	new = ft_lstnew(tmp->content, tmp->content_size);
	new_start = new;
	lst = lst->next;
	if (new_start)
	{
		while (lst)
		{
			tmp = (*f)(lst);
			new->next = ft_lstnew(tmp->content, tmp->content_size);
			if (new->next)
			{
				new = new->next;
				lst = lst->next;
			}
			else
				return (NULL);
		}
	}
	return (new_start);
}
