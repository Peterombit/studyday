/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykirigay <ykirigay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 14:42:58 by ykirigay          #+#    #+#             */
/*   Updated: 2019/09/24 21:14:17 by ykirigay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		l;
	int		i;

	i = 0;
	l = 0;
	while (src[l] != '\0')
	{
		l++;
	}
	if (!(dest = (char *)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	while (i < l)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
