/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykirigay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:59:33 by ykirigay          #+#    #+#             */
/*   Updated: 2020/02/10 18:59:36 by ykirigay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static int		revert_map(t_game *game, t_piece *piece, int w, int h)
{
	int		i;
	int		j;

	j = 0;
	w = (h > 0 ? piece->width - 1 : w);
	while (j <= h)
	{
		i = 0;
		while (i <= w)
		{
			if (game->map[piece->y + j][piece->x + i] == piece->letter)
				game->map[piece->y + j][piece->x + i] = CEMPTY;
			i++;
		}
		j++;
	}
	return (0);
}

static int		add_to_map(t_game *game, t_piece *piece)
{
	int		i;
	int		j;
	int		start;

	j = 0;
	start = 1;
	if (game->map[piece->y][piece->x] != CEMPTY && piece->map[0][0] != CEMPTY)
		return (0);
	while (start && j < piece->height)
	{
		i = 0;
		while (start && i < piece->width)
		{
			if (game->map[piece->y + j][piece->x + i] != CEMPTY
					&& piece->map[j][i] != CEMPTY)
				start = 0;
			else if (game->map[piece->y + j][piece->x + i] == CEMPTY)
				game->map[piece->y + j][piece->x + i] = piece->map[j][i];
			i = (start) ? i + 1 : i;
		}
		j = (start) ? j + 1 : j;
	}
	if (start)
		return (1);
	return (revert_map(game, piece, i, j));
}

static int		check_awnser(t_game *game, t_piece *pc)
{
	if (!pc)
		return (1);
	pc->x = 0;
	pc->y = 0;
	while (pc->y + pc->height <= game->size)
	{
		pc->x = 0;
		while (pc->x + pc->width <= game->size)
		{
			if (add_to_map(game, pc))
			{
				if (check_awnser(game, pc->next))
					return (1);
				else
					revert_map(game, pc, pc->width - 1, pc->height - 1);
			}
			pc->x++;
		}
		pc->y++;
	}
	return (0);
}

void			solve(t_game *game)
{
	int		j;

	while (!check_awnser(game, game->pieces))
	{
		game->size++;
		j = 0;
		while (j < game->size)
			ft_memset(game->map[j++], CEMPTY, game->size);
	}
}
