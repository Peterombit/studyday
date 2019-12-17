/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykirigay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 06:00:26 by ykirigay          #+#    #+#             */
/*   Updated: 2019/12/17 01:18:52 by ykirigay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	t_gnl		*ft_fetch(t_gnl **list, const int fd)
{
	t_gnl	*nlst;

	nlst = *list;
	while (nlst)
	{
		if (nlst->fd == fd)
			return (nlst);
		nlst = nlst->next;
	}
	TEST_MEM((nlst = (t_gnl *)malloc(sizeof(t_gnl))));
	nlst->fd = fd;
	nlst->buffer = NULL;
	nlst->next = *list;
	*list = nlst;
	return (nlst);
}

static char			*ft_new(t_gnl *curr, char buffer[BUFF_SIZE + 1])
{
	char	*tmp;
	char	*sub;
	char	*nlc;
	char	*str;
	size_t	size;

	str = ft_strnew(0);
	while (!(nlc = ft_strchr(buffer, '\n')))
	{
		BUBBLE_SORT(tmp, str, ft_strjoin(str, buffer));
		if (!(size = read(curr->fd, buffer, BUFF_SIZE)))
		{
			ft_strdel(&(curr->buffer));
			return (str);
		}
		buffer[size] = '\0';
	}
	sub = ft_strsub(buffer, 0, NL_INDEX);
	BUBBLE_SORT(tmp, str, ft_strjoin(str, sub));
	free(sub);
	BUBBLE_SORT(tmp, curr->buffer,
			ft_strsub(buffer, NL_INDEX + 1, BUFF_SIZE - NL_INDEX));
	return (str);
}

int					get_next_line(const int fd, char **line)
{
	static t_gnl	*list = NULL;
	t_gnl			*curr;
	char			buffer[BUFF_SIZE + 1];
	size_t			size;

	if (fd < 0 || read(fd, NULL, 0) == -1 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	curr = ft_fetch(&list, fd);
	if (curr->buffer && ft_strlen(curr->buffer))
		ft_strcpy(buffer, curr->buffer);
	else
	{
		if (!(size = read(fd, buffer, BUFF_SIZE)))
		{
			ft_strdel(&(curr->buffer));
			return (0);
		}
		buffer[size] = '\0';
	}
	*line = ft_new(curr, buffer);
	return (1);
}
