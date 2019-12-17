/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykirigay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 19:05:45 by ykirigay          #+#    #+#             */
/*   Updated: 2019/09/24 19:50:47 by ykirigay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	num;
	int charge;

	if (n < (-2147483647))
	{
		ft_putstr_fd("-2", fd);
		ft_putnbr_fd(147483648, fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	num = n;
	charge = 1;
	while ((num = num / 10) > 0)
		charge *= 10;
	while (charge > 0)
	{
		ft_putchar_fd(n / charge + '0', fd);
		n %= charge;
		charge /= 10;
	}
}
