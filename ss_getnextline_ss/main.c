/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykirigay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 20:52:19 by ykirigay          #+#    #+#             */
/*   Updated: 2019/11/20 21:31:23 by ykirigay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd1;
    int fd2;
	char	*line;

	if (argc > 1)
	{
		fd1 = open(argv[1], O_RDONLY);
        fd2 = open(argv[2], O_RDONLY);
		while (get_next_line(fd1, &line) > 0)
		{
			printf("%s\n", line);
			free(line);
		}
        while (get_next_line(fd2, &line) > 0)
        {
            printf("%s\n", line);
            free(line);
        }
    }
	return (0);
}	
