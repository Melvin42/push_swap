/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_chunk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 01:15:44 by melperri          #+#    #+#             */
/*   Updated: 2021/12/14 21:35:32 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap_rot_or_rev(t_list **a, t_list **b, t_env *g, int *tab)
{
	if ((*a)->next && *b)
	{
		if (ft_is_next(*b, (*a)->next->index, g) == 1)
			ft_swap_lst(a, SA, NULL, g);
		else
		{
			if (ft_search_next_to_push(*a, g, tab) == FRONT)
				ft_rotate(a, RA, NULL, g);
			else
				ft_reverse_rotate(a, RRA, NULL, g);
		}
	}
	else
	{
		if (ft_search_next_to_push(*a, g, tab) == FRONT)
			ft_rotate(a, RA, NULL, g);
		else
			ft_reverse_rotate(a, RRA, NULL, g);
	}
}

int	ft_create_chunk(t_list **a, t_list **b, t_env *g)
{
	int	*tab;

	tab = ft_list_to_tab(*a);
	if (tab == NULL)
		return (-1);
	while (lst_size(*b) < g->chunk_size)
	{
		if ((*a)->index >= g->chunk_min && (*a)->index <= g->chunk_max)
		{
			if (lst_size(*b) > 1)
			{
				if (ft_prepare_b(b, (*a)->index, g) == -1)
					return (-1);
				ft_push(a, b, PB, g);
			}
			else
				ft_push(a, b, PB, g);
		}
		else
			ft_swap_rot_or_rev(a, b, g, tab);
	}
	ft_free((void **)&tab);
	return (0);
}
