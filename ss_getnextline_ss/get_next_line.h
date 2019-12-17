/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykirigay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 06:01:26 by ykirigay          #+#    #+#             */
/*   Updated: 2019/11/20 21:00:09 by ykirigay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include "libft/libft.h"

# define BUFF_SIZE 1
# define TEST_MEM(x) if (!x) return(0);
# define BUBBLE_SORT(x, y, z) x = y; y = z; free(x);
# define NL_INDEX (nlc - buffer)

typedef struct		s_gnl
{
	int				fd;
	char			*buffer;
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(const int fd, char **line);

#endif
