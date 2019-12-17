/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykirigay <ykirigay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 17:32:39 by ykirigay          #+#    #+#             */
/*   Updated: 2019/09/20 18:59:51 by ykirigay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *c)
{
	int i;

	if (*c == '\0')
		return ((char *)haystack);
	while (*haystack != '\0')
	{
		i = 0;
		while (c[i] == haystack[i] && c[i] != '\0')
			i++;
		if (c[i] == '\0')
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
