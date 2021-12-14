/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 01:06:45 by melperri          #+#    #+#             */
/*   Updated: 2021/12/14 21:18:40 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_find_max_rotate_or_reverse(t_list **b, t_env *g, int *tab)
{
	int	ref;

	ref = ft_find_max(*b, tab);
	if (ft_search_nbr(*b, ref, tab) == FRONT)
		while ((*b)->index != ref)
			ft_rotate(b, RB, NULL, g);
	else
		while ((*b)->index != ref)
			ft_reverse_rotate(b, RRB, NULL, g);
}

int	ft_prepare_b(t_list **b, int to_move, t_env *g)
{
	int	*tab;

	tab = NULL;
	tab = ft_list_to_tab(*b);
	if (tab == NULL)
		return (-1);
	if (it_is_new_min(b, to_move) == 1 || it_is_new_max(b, to_move) == 1)
		ft_find_max_rotate_or_reverse(b, g, tab);
	else
	{
		if (ft_search_new_pos(*b, to_move, tab) == FRONT)
			while (!(to_move >= (*b)->index && to_move <= lst_last(*b)->index))
				ft_rotate(b, RB, NULL, g);
		else
			while (!(to_move >= (*b)->index && to_move <= lst_last(*b)->index))
				ft_reverse_rotate(b, RRB, NULL, g);
	}
	ft_free((void **)&tab);
	return (0);
}
