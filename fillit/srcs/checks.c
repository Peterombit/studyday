/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykirigay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 23:30:29 by ykirigay          #+#    #+#             */
/*   Updated: 2020/02/07 23:30:33 by ykirigay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static int		is_valid(int c, int i)
{
	if (c == CEMPTY || c == CBLOCK
	|| ((c == '\n') && ((i % 5 == 4) || (i == 20))))
		return (1);
	return (0);
}

static int		check_field(char *buf, int i)
{
	int		res;

	if (i == 19)
		return (0);
	res = 0;
	if (buf[i] == CBLOCK)
	{
		if (i > 0 && buf[i - 1] == CBLOCK)
			res++;
		if (i < 19 && buf[i + 1] == CBLOCK)
			res++;
		if (i >= 5 && buf[i - 5] == CBLOCK)
			res++;
		if (i <= 14 && buf[i + 5] == CBLOCK)
			res++;
	}
	return (res + check_field(buf, ++i));
}

static int		check_block(char *buf)
{
	int		i;
	int		nb_loc;
	int		first_loc;
	int		ret;

	i = 0;
	nb_loc = 0;
	while (buf[i] && is_valid(buf[i], i) && nb_loc <= 4)
	{
		if (buf[i] == CBLOCK)
		{
			nb_loc++;
			if (nb_loc == 1)
				first_loc = i;
		}
		i++;
	}
	if (i >= 20 && !buf[i] && nb_loc == 4
	&& (ret = check_field(buf, first_loc))
	&& (ret == 6 || ret == 8))
		return (1);
	else
		dp_error(2);
	return (0);
}

int				loop_files(t_game *game, char *file)
{
	int		fd;
	int		ret;
	int		last_ret;
	char	buf[22];

	ret = 0;
	last_ret = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		dp_error(2);
	while ((ret = read(fd, buf, 21)) > 0)
	{
		last_ret = ret;
		buf[ret] = '\0';
		if (ret >= 20 && check_block(buf))
			store_block(game, buf);
		else
			dp_error(2);
	}
	if (ret <= 0 && (last_ret == 21 || !last_ret))
		dp_error(2);
	return (1);
}
