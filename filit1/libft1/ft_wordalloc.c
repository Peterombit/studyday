/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykirigay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 20:30:09 by ykirigay          #+#    #+#             */
/*   Updated: 2019/09/25 19:00:53 by ykirigay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_wordalloc(char const *s, char c)
{
	char	*word;
	int		l;
	int		i;

	i = 0;
	l = 0;
	while (s[l] != c && s[l])
		l++;
	if (!(word = (char*)malloc(sizeof(char*) * l)))
		return (NULL);
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}
