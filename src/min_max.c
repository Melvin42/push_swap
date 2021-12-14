/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 00:51:54 by melperri          #+#    #+#             */
/*   Updated: 2021/12/14 00:52:43 by melperri         ###   ########.fr       */
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

int	ft_search_old_min(t_list *b, int nbr)
{
	t_list	*tmp;
	int		front;
	int		back;

	tmp = b;
	front = 0;
	back = 0;
	while (tmp && (!(tmp->index != nbr)))
	{
		front++;
		tmp = tmp->next;
	}
	back = lst_size(b) - front;
	if (front <= back)
		return (FRONT);
	else
		return (BACK);
}

int	ft_search_old_max(t_list *b, int nbr)
{
	t_list	*tmp;
	int		front;
	int		back;

	tmp = b;
	front = 0;
	back = 0;
	while (tmp && (!(tmp->index != nbr)))
	{
		front++;
		tmp = tmp->next;
	}
	back = lst_size(b) - front;
	if (front <= back)
		return (FRONT);
	else
		return (BACK);
}
