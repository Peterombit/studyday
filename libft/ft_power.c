/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeowth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 19:38:49 by cmeowth           #+#    #+#             */
/*   Updated: 2020/02/28 19:38:53 by cmeowth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double			ft_power(double nb, double power)
{
	if (power < 0.0)
		return (0);
	if (power == 0.0)
		return (1);
	if (power > 308)
		return (1);
	return (nb * ft_power(nb, power - 1));
}
