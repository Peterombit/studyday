/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdelsie <vdelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 18:42:30 by nmei              #+#    #+#             */
/*   Updated: 2019/12/14 19:24:25 by vdelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*map_str;
	char	*start;
	size_t	len;

	if (s && (*f))
	{
		len = ft_strlen(s);
		map_str = (char *)malloc((len + 1) * sizeof(*map_str));
		if (map_str)
		{
			map_str[len] = '\0';
			start = map_str;
			while (len--)
			{
				*map_str++ = (*f)(*s++);
			}
			return (start);
		}
	}
	return (NULL);
}
