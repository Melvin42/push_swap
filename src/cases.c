/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:39:32 by melperri          #+#    #+#             */
/*   Updated: 2021/10/15 00:07:37 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_case_two(t_list *a)
{
	int	b;

	b = a->next->data;
	if (a->data > b)
		ft_write(RA);
}

void	ft_case_three(t_list **a)
{
	int	b;
	int	c;

	b = (*a)->next->data;
	c = (*a)->next->next->data;
	if ((*a)->data > b && b < c && (*a)->data < c)
		ft_swap_lst(a, SA, NULL);
	else if ((*a)->data > b && b > c && (*a)->data > c)
	{
		ft_rotate(a, RA, NULL);
		ft_swap_lst(a, SA, NULL);
	}
	else if ((*a)->data > b && b < c && (*a)->data > c)
		ft_rotate(a, RA, NULL);
	else if ((*a)->data < b && b > c && (*a)->data > c)
		ft_reverse_rotate(a, RRA, NULL);
	else if ((*a)->data < b && b > c && (*a)->data < c)
	{
		ft_swap_lst(a, SA, NULL);
		ft_rotate(a, RA, NULL);
	}
}

void	ft_case_four(t_list **a, t_list **b)
{
	while (lst_size(*b) < 1)
	{
		if ((*a)->index == 0)
			ft_push(a, b, PB);
		else
			ft_rotate(a, RA, NULL);
	}
	ft_case_three(a);
	ft_push(b, a, PA);
}

void	ft_case_five(t_list **a, t_list **b)
{
	int	median;

	median = ft_search_median(*a);
	while (lst_size(*b) < median)
	{
		if ((*a)->index < median)
			ft_push(a, b, PB);
		else
			ft_rotate(a, RA, NULL);
	}
	ft_case_three(a);
	if ((*b)->index > (*b)->next->index)
		ft_push(b, a, PA);
	else
	{
		ft_rotate(b, RB, NULL);
		ft_push(b, a, PA);
	}
	ft_push(b, a, PA);
}


int	ft_case_hundred(t_list **a, t_list **b)
{
	(void)a;
	(void)b;
	return (0);
}

int	ft_case_five_hundred(t_list **a, t_list **b)
{
	(void)a;
	(void)b;
	return (0);
}

int	ft_check_case(t_list **a, t_list **b, int ac)
{
	if (ac == 3)
		ft_case_two(*a);
	else if (ac == 4)
		ft_case_three(a);
	else if (ac == 5)
		ft_case_four(a, b);
	else if (ac == 6)
		ft_case_five(a, b);
	else if (ac > 5 && ac <= 101)
	{
		if (ft_case_hundred(a, b) != 0)
			return (-1);
	}
	else if (ac > 101 && ac <= 501)
	{
		if (ft_case_five_hundred(a, b) != 0)
			return (-1);
	}
	return (0);
}
