/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdelsie <vdelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 19:33:48 by nmei              #+#    #+#             */
/*   Updated: 2019/12/14 19:24:25 by vdelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		remainder;
	size_t		dlen;
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	remainder = size;
	while (remainder-- != 0 && *d)
		d++;
	dlen = d - dst;
	remainder = size - dlen;
	if (remainder == 0)
		return (dlen + ft_strlen(s));
	while (*s)
	{
		if (remainder != 1)
		{
			*d++ = *s;
			remainder--;
		}
		s++;
	}
	*d = '\0';
	return (dlen + (s - src));
}
