/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeowth <cmeowth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 23:57:40 by cmeowth           #+#    #+#             */
/*   Updated: 2020/02/29 07:02:55 by ykirigay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	int		i;
	char	*s2;

	i = 0;
	if (!(s2 = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (NULL);
	while (*s1)
	{
		s2[i] = *s1++;
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
