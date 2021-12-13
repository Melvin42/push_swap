/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:39:32 by melperri          #+#    #+#             */
/*   Updated: 2021/12/13 06:01:36 by melperri         ###   ########.fr       */
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

void	ft_case_three(t_list **a, t_env *g)
{
	int	b;
	int	c;

	b = (*a)->next->data;
	c = (*a)->next->next->data;
	if ((*a)->data > b && b < c && (*a)->data < c)
		ft_swap_lst(a, SA, NULL, g);
	else if ((*a)->data > b && b > c && (*a)->data > c)
	{
		ft_rotate(a, RA, NULL, g);
		ft_swap_lst(a, SA, NULL, g);
	}
	else if ((*a)->data > b && b < c && (*a)->data > c)
		ft_rotate(a, RA, NULL, g);
	else if ((*a)->data < b && b > c && (*a)->data > c)
		ft_reverse_rotate(a, RRA, NULL, g);
	else if ((*a)->data < b && b > c && (*a)->data < c)
	{
		ft_swap_lst(a, SA, NULL, g);
		ft_rotate(a, RA, NULL, g);
	}
}

void	ft_case_four(t_list **a, t_list **b, t_env *g)
{
	while (lst_size(*b) < 1)
	{
		if ((*a)->index == 0)
			ft_push(a, b, PB, g);
		else
			ft_rotate(a, RA, NULL, g);
	}
	ft_case_three(a, g);
	ft_push(b, a, PA, g);
}

void	ft_case_five(t_list **a, t_list **b, t_env *g)
{
	int	median;

	median = ft_search_median(*a);
	while (lst_size(*b) < median)
	{
		if ((*a)->index < median)
			ft_push(a, b, PB, g);
		else
			ft_rotate(a, RA, NULL, g);
	}
	ft_case_three(a, g);
	if ((*b)->index > (*b)->next->index)
		ft_push(b, a, PA, g);
	else
	{
		ft_rotate(b, RB, NULL, g);
		ft_push(b, a, PA, g);
	}
	ft_push(b, a, PA, g);
}

int	ft_check_case(t_list **a, t_list **b, int ac, t_env *g)
{
	if (ac == 3)
		ft_case_two(*a);
	else if (ac == 4)
		ft_case_three(a, g);
	else if (ac == 5)
		ft_case_four(a, b, g);
	else if (ac == 6)
		ft_case_five(a, b, g);
	else
	{
		if (ft_chunk(a, b, g) != 0)
			return (-1);
	}
	return (0);
}
