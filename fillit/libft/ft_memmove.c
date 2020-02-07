/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykirigay <ykirigay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:15:51 by ykirigay          #+#    #+#             */
/*   Updated: 2019/09/25 17:36:35 by ykirigay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*p_dst;
	unsigned char	*p_src;
	size_t			i;

	if (!src && !dst)
		return (NULL);
	i = 0;
	p_dst = (unsigned char *)dst;
	p_src = (unsigned char *)src;
	if (src < dst)
	{
		while (++i <= len)
			p_dst[len - i] = p_src[len - i];
	}
	else
	{
		while (len-- > 0)
		{
			p_dst[i] = p_src[i];
			i++;
		}
	}
	return (dst);
}
