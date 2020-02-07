/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykirigay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 23:31:43 by ykirigay          #+#    #+#             */
/*   Updated: 2020/02/07 23:31:46 by ykirigay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static t_coord		get_coords(char *buf)
{
	t_coord		coord;
	int			index;

	coord.t = 3;
	coord.r = 0;
	coord.b = 0;
	coord.l = 3;
	index = 0;
	while (buf[index])
	{
		if (buf[index] == CBLOCK)
		{
			if (index / 5 < coord.t)
				coord.t = index / 5;
			if (index / 5 > coord.b)
				coord.b = index / 5;
			if (index % 5 > coord.r)
				coord.r = index % 5;
			if (index % 5 < coord.l)
				coord.l = index % 5;
		}
		index++;
	}
	return (coord);
}

static t_place		*init_place(char *buf)
{
	t_place		*new;
	t_coord		pts;
	int			i;
	static char	c = 'A';

	if (!(new = ft_memalloc(sizeof(t_place))))
		dp_error(2);
	new->x = 0;
	new->y = 0;
	new->letter = c++;
	new->next = NULL;
	pts = get_coords(buf);
	new->width = pts.r - pts.l + 1;
	new->height = pts.b - pts.t + 1;
	if (!(new->map = (char **)malloc(new->height * sizeof(char *))))
		dp_error(2);
	i = 0;
	while (i < new->height)
	{
		new->map[i] = buf_to_piece(buf,
				((pts.t + i) * 5 + pts.l), new->width, new->letter);
		i++;
	}
	return (new);
}

void				store_block(t_game *game, char *buf)
{
	t_place		*new;

	new = init_place(buf);
	pushback_place(game, new);
}
