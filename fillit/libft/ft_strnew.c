/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykirigay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 19:15:40 by ykirigay          #+#    #+#             */
/*   Updated: 2019/09/25 20:15:26 by ykirigay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;

	if (!(size + 1))
		return (NULL);
	if (!(new = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memset(new, '\0', size + 1);
	return (new);
}
