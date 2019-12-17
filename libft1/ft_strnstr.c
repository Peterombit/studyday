/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykirigay <ykirigay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 17:36:34 by ykirigay          #+#    #+#             */
/*   Updated: 2019/09/26 18:30:32 by ykirigay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *lak, size_t len)
{
	size_t		i;
	int			k;
	size_t		m;

	i = 0;
	k = 0;
	m = 0;
	if (lak[i] == '\0')
		return ((char *)str);
	while (str[i] != '\0')
	{
		k = 0;
		while (str[i + m] != '\0' && lak[m] != '\0' && k != 1 && (i + m < len))
			if (lak[m] == str[i + m])
				m++;
			else
			{
				k = 1;
				m = 0;
			}
		if (lak[m] == '\0')
			return ((char*)(str + i));
		i++;
	}
	return (0);
}
