/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykirigay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:58:20 by ykirigay          #+#    #+#             */
/*   Updated: 2020/02/10 18:58:23 by ykirigay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	dp_error(int c)
{
	if (c == 1)
		ft_putstr_fd(ERR1, 1);
	else if (c == 2)
		ft_putstr_fd(ERR2, 1);
	exit(1);
}
