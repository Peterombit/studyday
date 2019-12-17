/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykirigay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:54:08 by ykirigay          #+#    #+#             */
/*   Updated: 2019/09/24 19:24:44 by ykirigay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	unsigned int	temp;

	temp = 0;
	while (src[temp] != '\0')
	{
		dst[temp] = src[temp];
		temp++;
	}
	dst[temp] = '\0';
	return (dst);
}
