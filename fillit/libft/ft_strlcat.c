/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykirigay <ykirigay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:35:28 by ykirigay          #+#    #+#             */
/*   Updated: 2019/09/20 19:07:05 by ykirigay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	ld;
	size_t	j;
	size_t	i;
	size_t	ls;

	ls = ft_strlen(src);
	j = 0;
	ld = ft_strlen(dst);
	i = ld;
	if (n < ld + 1)
		return (ls + n);
	if (n > ld + 1)
	{
		while (src[j] && i < n - 1)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
	}
	dst[i] = '\0';
	return (ld + ls);
}
