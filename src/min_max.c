/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 00:51:54 by melperri          #+#    #+#             */
/*   Updated: 2021/12/14 13:19:26 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	it_is_new_min(t_list **b, int to_move)
{
	t_list	*tmp;

	tmp = *b;
	while (tmp)
	{
		if (tmp->index < to_move)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	it_is_new_max(t_list **b, int to_move)
{
	t_list	*tmp;

	tmp = *b;
	while (tmp)
	{
		if (tmp->index > to_move)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_search_nbr(t_list *b, int nbr, int *tab)
{
	int		front;
	int		back;
	int		j;

	j = 0;
	front = 0;
	back = lst_size(b) - 1;
	while (front < back && tab[front] != nbr)
		front++;
	while (back > 0 && tab[back] != nbr)
	{
		back--;
		j++;
	}
	if (front <= j)
		return (FRONT);
	else
		return (BACK);
}
