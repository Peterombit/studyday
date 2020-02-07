/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykirigay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 12:15:32 by ykirigay          #+#    #+#             */
/*   Updated: 2019/09/20 19:07:24 by ykirigay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	sym;

	sym = (char)c;
	while (*s)
	{
		if (*s == sym)
			return ((char *)s);
		s++;
	}
	if (*s == '\0' && sym == '\0')
		return ((char *)s);
	return (NULL);
}
