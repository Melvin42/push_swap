/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:25:09 by melperri          #+#    #+#             */
/*   Updated: 2021/10/14 17:12:36 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_write(char *str)
{
	if (ft_strcmp(str, SA) == 0)
		write(1, "sa\n", 3);
	else if (ft_strcmp(str, SB) == 0)
		write(1, "sb\n", 3);
	else if (ft_strcmp(str, SS) == 0)
		write(1, "ss\n", 3);
	else if (ft_strcmp(str, PA) == 0)
		write(1, "pa\n", 3);
	else if (ft_strcmp(str, PB) == 0)
		write(1, "pb\n", 3);
	else if (ft_strcmp(str, RA) == 0)
		write(1, "ra\n", 3);
	else if (ft_strcmp(str, RB) == 0)
		write(1, "rb\n", 3);
	else if (ft_strcmp(str, RR) == 0)
		write(1, "rb\n", 3);
	else if (ft_strcmp(str, RRA) == 0)
		write(1, "rra\n", 4);
	else if (ft_strcmp(str, RRB) == 0)
		write(1, "rrb\n", 4);
	else if (ft_strcmp(str, RRR) == 0)
		write(1, "rrr\n", 4);
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

int	ft_isspace(int c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *nptr)
{
	unsigned long int	res;
	int					sign;

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
	if (res > LONG_MAX && sign == -1)
		return (0);
	else if (res > LONG_MAX && sign == 1)
		return (-1);
	return (res * sign);
}
