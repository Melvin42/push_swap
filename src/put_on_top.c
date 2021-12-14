/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_on_top.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 01:03:29 by melperri          #+#    #+#             */
/*   Updated: 2021/12/14 01:03:54 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_put_min_on_the_top(t_list **b, t_env *g)
{
	if (g->chunk_min != 0)
	{
		while ((*b)->index != g->chunk_max - g->chunk_size + 1)
			ft_rotate(b, RB, NULL, g);
	}
	else
		while ((*b)->index != 0)
			ft_rotate(b, RB, NULL, g);
}

int	ft_put_max_on_the_top(t_list **b, t_env *g)
{
	int	ref;
	int	*tab;

	tab = ft_list_to_tab(*b);
	if (tab == NULL)
		return (-1);
	ref = ft_find_max(*b, tab);
	if (ft_search_old_max(*b, ref) == FRONT)
	{
		while ((*b)->index != g->chunk_max)
			ft_rotate(b, RB, NULL, g);
	}
	else
		while ((*b)->index != g->chunk_max)
			ft_reverse_rotate(b, RRB, NULL, g);
	free(tab);
	return (0);
}

int	ft_put_nbr_on_the_top(t_list *a, int nbr)
{
	t_list	*tmp;
	int		front;
	int		back;

	tmp = a;
	front = 0;
	back = 0;
	while (tmp && tmp->index != nbr)
	{
		front++;
		tmp = tmp->next;
	}
	back = lst_size(a) - front;
	if (front <= back)
		return (FRONT);
	else
		return (BACK);
}
