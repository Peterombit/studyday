/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 15:35:16 by vinograd          #+#    #+#             */
/*   Updated: 2020/02/29 07:57:03 by ykirigay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putstr(char const *s)
{
	size_t i;

	i = 0;
	if (s != NULL)
		while (s[i] != '\0')
			ft_putchar(s[i++]);
	return (i);
}
