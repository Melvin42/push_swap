/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:39:32 by melperri          #+#    #+#             */
/*   Updated: 2021/10/13 13:41:45 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_case_two(t_list *a)
{
	int	b;

	b = a->next->data;
	if (a->data > b)
		ft_write("RA");
}

void	ft_case_three(t_list *a)
{
	int	b;
	int	c;

	b = a->next->data;
	c = a->next->next->data;
	if (a->data > b && b < c && a->data < c)
		ft_write("SA");
	else if (a->data < b && b > c && a->data > c)
		ft_write("RRA");
	else if (a->data > b && b > c && a->data > c)
	{
		ft_write("RA");
		ft_write("SA");
	}
	else if (a->data < b && b > c && a->data < c)
	{
		ft_write("SA");
		ft_write("RA");
	}
}

void	ft_case_four(t_list *a)
{
	(void)a;
}

void	ft_case_five(t_list *a)
{
	(void)a;
}

int	ft_case_hundred(t_list *a)
{
	(void)a;
	t_list	*b;

	b = malloc(sizeof(*b));
	b = NULL;
	return (0);
}

int	ft_case_five_hundred(t_list *a)
{
	(void)a;
	t_list	*b;

	b = malloc(sizeof(*b));
	b = NULL;
	return (0);
}

int	ft_check_case(t_list *a, int ac)
{
	if (ac == 3)
		ft_case_two(a);
	else if (ac == 4)
		ft_case_three(a);
	else if (ac == 5)
		ft_case_four(a);
	else if (ac == 6)
		ft_case_five(a);
	else if (ac > 5 && ac <= 101)
	{
		if (ft_case_hundred(a) != 0)
			return (-1);
	}
	else if (ac > 101 && ac <= 501)
	{
		if (ft_case_five_hundred(a) != 0)
			return (-1);
	}
	return (0);
}
