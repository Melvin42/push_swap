/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_int_max.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:09:04 by melperri          #+#    #+#             */
/*   Updated: 2021/12/14 18:44:25 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
		;
	return (i);
}

long	ft_atol(const char *nptr)
{
	unsigned long	res;
	long			sign;

	res = 0;
	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	while (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		res = res * 10 + (*nptr - 48);
		nptr++;
	}
	if (res > LLONG_MAX && sign == -1)
		return (0);
	else if (res > LLONG_MAX && sign == 1)
		return (-1);
	return (res * sign);
}

int	ft_check_int_max(char **av)
{
	int		i;
	long	min;
	long	max;
	long	nbr;

	min = INT_MIN;
	max = INT_MAX;
	i = 0;
	while (av[++i])
	{
		if (ft_strlen(av[i]) > 11)
			return (-1);
		nbr = ft_atol(av[i]);
		if (nbr > max || nbr < min)
			return (-1);
	}
	return (0);
}
