/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:39:44 by vinograd          #+#    #+#             */
/*   Updated: 2020/02/29 07:57:03 by ykirigay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *s)
{
	int		len;
	char	*str;

	len = 0;
	while (s[len])
		len++;
	str = (char*)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	while (len >= 0)
	{
		str[len] = s[len];
		len--;
	}
	return (str);
}
