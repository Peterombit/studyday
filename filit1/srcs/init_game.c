/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykirigay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:59:04 by ykirigay          #+#    #+#             */
/*   Updated: 2020/02/10 18:59:08 by ykirigay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char			*buf_to_piece(char const *s, unsigned int start,
				size_t len, char l)
{
	char			*res;
	unsigned int	index;

	if (!s)
		return (NULL);
	res = ft_strnew(len);
	if (!res)
		return (NULL);
	index = 0;
	while (index < len)
	{
		if (s[start + index] == CBLOCK)
			res[index] = l;
		else
			res[index] = s[start + index];
		index++;
	}
	return (res);
}

static int		sqrt_ceil(int nb)
{
	int		i;

	i = 1;
	while (i * i < nb)
		i++;
	return (i);
}

static int		set_map(t_game *game, int size)
{
	int		i;

	if (!(game->map = (char **)malloc(size * sizeof(char *))))
		return (0);
	i = 0;
	while (i < size)
	{
		if (!(game->map[i] = (char *)malloc(size * sizeof(char))))
			return (0);
		ft_memset(game->map[i++], CEMPTY, (size_t)size);
	}
	return (1);
}

int				init_game(t_game *game, char *file)
{
	game->pieces = NULL;
	game->nb_pieces = 0;
	game->map = NULL;
	if (loop_files(game, file))
	{
		set_map(game, 4 * game->nb_pieces);
		game->size = 2 * sqrt_ceil(game->nb_pieces) - 1;
		return (1);
	}
	return (0);
}
