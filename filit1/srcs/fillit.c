/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykirigay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:58:28 by ykirigay          #+#    #+#             */
/*   Updated: 2020/02/10 18:58:47 by ykirigay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static void		free_map(t_game *game)
{
	int		i;

	i = 0;
	if (game->map)
	{
		while (i < 4 * game->nb_pieces)
			free(game->map[i++]);
		free(game->map);
		game->map = NULL;
	}
}

void			put_map(t_game *game)
{
	int		i;
	int		j;

	j = 0;
	while (j < game->size)
	{
		i = 0;
		while (i < game->size)
			ft_putchar(game->map[j][i++]);
		ft_putchar('\n');
		j++;
	}
}

void			pushback_place(t_game *game, t_piece *piece)
{
	t_piece		*lst;

	lst = game->pieces;
	if (!lst)
	{
		game->pieces = piece;
		game->nb_pieces++;
		return ;
	}
	while (lst->next)
		lst = lst->next;
	lst->next = piece;
	game->nb_pieces++;
}

int				main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		dp_error(1);
		return (0);
	}
	if (init_game(&game, av[1]))
	{
		solve(&game);
		put_map(&game);
		free_map(&game);
	}
	else
		dp_error(2);
	return (1);
}
