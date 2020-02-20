/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdelsie <vdelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 19:53:06 by nmei              #+#    #+#             */
/*   Updated: 2019/12/14 19:24:25 by vdelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstrev(t_list **begin_list)
{
	t_list *new_begin;
	t_list *temp_next;

	if (begin_list)
	{
		new_begin = NULL;
		while (*begin_list)
		{
			temp_next = (*begin_list)->next;
			(*begin_list)->next = new_begin;
			new_begin = *begin_list;
			*begin_list = temp_next;
		}
		*begin_list = new_begin;
	}
}
