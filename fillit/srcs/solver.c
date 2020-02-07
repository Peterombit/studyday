/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykirigay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 23:31:26 by ykirigay          #+#    #+#             */
/*   Updated: 2020/02/07 23:31:29 by ykirigay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static int		revert_map(t_game *game, t_place *place, int w, int h)
{
	int		i;
	int		j;

	j = 0;
	w = (h > 0 ? place->width - 1 : w);
	while (j <= h)
	{
		i = 0;
		if (i <= w)
		{
			if (game->map[place->y + j][place->x + i] == place->letter)
				game->map[place->y + j][place->x + i] = CEMPTY;
			i++;
		}
		j++;
	}
	return (0);
}

static int		add_to_map(t_game *game, t_place *place)
{
	int		i;
	int		j;
	int		start;

	j = 0;
	start = 1;
	if (game->map[place->y][place->x] != CEMPTY && place->map[0][0] != CEMPTY)
		return (0);
	while (start && j < place->height)
	{
		i = 0;
		while (start && i < place->width)
		{
			if (game->map[place->y + j][place->x + i] != CEMPTY
					&& place->map[j][i] != CEMPTY)
				start = 0;
			else if (game->map[place->y + j][place->x + i] == CEMPTY)
				game->map[place->y + j][place->x + i] = place->map[j][i];
			i = (start) ? i + 1 : i;
		}
		j = (start) ? j + 1 : j;
	}
	if (start)
		return (1);
	return (revert_map(game, place, i, j));
}

static int		check_awnser(t_game *game, t_place *pc)
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
