/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykirigay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 23:28:49 by ykirigay          #+#    #+#             */
/*   Updated: 2020/02/07 23:28:52 by ykirigay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>

# define CBLOCK '#'
# define CEMPTY '.'

# define ERR1 "usage: ./fillit source_file\n"
# define ERR2 "error\n"

typedef	struct		s_coord
{
	int				t;
	int				r;
	int				b;
	int				l;
}					t_coord;

typedef	struct		s_place
{
	int				x;
	int				y;
	int				width;
	int				height;
	char			**map;
	char			letter;
	struct s_place	*next;
}					t_place;

typedef	struct		s_game
{
	t_place			*pieces;
	int				nb_pieces;
	int				size;
	char			**map;
}					t_game;

int					loop_files(t_game *game, char *file);
void				dp_error(int c);
void				put_map(t_game *game);
void				pushback_place(t_game *game, t_place *place);
int					init_game(t_game *game, char *file);
void				solve(t_game *game);
char				*buf_to_piece(char const *s, unsigned int start,
		size_t len, char l);
void				store_block(t_game *game, char *buf);

#endif
