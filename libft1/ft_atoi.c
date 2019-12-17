/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykirigay <ykirigay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 17:42:51 by ykirigay          #+#    #+#             */
/*   Updated: 2019/09/26 20:22:20 by ykirigay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(long long int a, const char *str, int i, int m)
{
	if ((((a * m) >= 922337203685477580) && ((str[i] - '0') > 7))
	|| ((a * m >= 1000000000000000000) && str[i]))
		return (-1);
	else if ((((a * m) <= -922337203685477580) && ((str[i] - '0') > 8))
	|| ((a * m <= -1000000000000000000) && str[i]))
		return (0);
	return (1);
}

int			ft_atoi(const char *str)
{
	long long int	a;
	int				sign;
	int				i;

	a = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' && str[i + 1] >= '0' && str[i + 1] <= '9')
		sign = -1;
	if ((str[i] == '-' || str[i] == '+') && (str[i + 1] >= '0' \
	&& str[i + 1] <= '9'))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (ft_check(a, str, i, sign) == -1)
			return (-1);
		else if (ft_check(a, str, i, sign) == 0)
			return (0);
		a = a * 10 + (str[i] - '0');
		i++;
	}
	return (a * sign);
}
