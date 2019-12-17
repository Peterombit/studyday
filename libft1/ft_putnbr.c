/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykirigay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 19:05:32 by ykirigay          #+#    #+#             */
/*   Updated: 2019/09/23 19:05:34 by ykirigay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int	num;
	int charge;

	if (n < (-2147483647))
	{
		ft_putstr("-2");
		ft_putnbr(147483648);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	num = n;
	charge = 1;
	while ((num = num / 10) > 0)
		charge *= 10;
	while (charge > 0)
	{
		ft_putchar(n / charge + '0');
		n %= charge;
		charge /= 10;
	}
}
