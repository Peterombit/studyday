/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdelsie <vdelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 19:28:15 by nmei              #+#    #+#             */
/*   Updated: 2019/12/14 19:24:25 by vdelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
**	If we get an empty string or only spaces string then we want to
**	return an empty string. We return ft_strdup("") becuase normally
**	the malloc'd "trim" would then be freed at some point. If we only returned
**	return(""); then trying to free a const char would end badly.
**
**	The (s || (trim = NULL)) is a stupid ugly hack because apparently if you
**	want function security and also want an under 25 line function, too bad...
**	(trim = NULL) part will always evaluate out to 'false'. If 's' doesn't exist
**	then we return trim, which we happened to assign as NULL. If 's' does exist
**	then great, 'True || False' (i.e. 's || (trim = NULL)') also turns true...
*/

static int	is_wspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	else
		return (0);
}

char		*ft_strtrim(char const *s)
{
	const char		*strt;
	const char		*end;
	char			*trim;
	char			*tmp;

	if (s || (trim = NULL))
	{
		while (is_wspace(*s))
			s++;
		if (*(strt = s) == '\0')
			return (ft_strdup(""));
		while (*s)
			s++;
		while (is_wspace(*s) || *s == '\0')
			s--;
		end = ++s;
		if ((trim = (char *)malloc(((end - strt) + 1) * sizeof(*trim))))
		{
			tmp = trim;
			while (end - strt != 0)
				*tmp++ = *strt++;
			*tmp = '\0';
		}
	}
	return (trim);
}
