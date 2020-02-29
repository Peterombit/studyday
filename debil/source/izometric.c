/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   izometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykirigay <ykirigay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 06:48:14 by ykirigay          #+#    #+#             */
/*   Updated: 2020/02/29 06:48:14 by ykirigay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	default angle: 0.523599
**	make the figure 3d (isometric stile)
*/

#include "fdf.h"

void	isometric(t_dot *dot, double angle)
{
	dot->x = (dot->x - dot->y) * cos(angle);
	dot->y = (dot->x + dot->y) * sin(angle) - dot->z;
}
