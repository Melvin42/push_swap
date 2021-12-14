/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_in_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 01:17:09 by melperri          #+#    #+#             */
/*   Updated: 2021/12/14 21:12:21 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate_or_reverse(t_list **a, t_env *g, int search, int *tab)
{
	if (ft_search_nbr(*a, search, tab) == FRONT)
		while ((*a)->index != search)
			ft_rotate(a, RA, NULL, g);
	else
		while ((*a)->index != search)
			ft_reverse_rotate(a, RRA, NULL, g);
}

int	ft_push_back_in_a(t_list **a, t_list **b, t_env *g, int max)
{
	int	*tab;

	tab = ft_list_to_tab(*a);
	if (tab == NULL)
		return (-1);
	if (g->chunk_max != max && g->chunk_max != g->chunk_size - 1)
		ft_rotate_or_reverse(a, g, g->chunk_max + 1, tab);
	else if (g->chunk_max == g->chunk_size - 1)
	{
		ft_rotate_or_reverse(a, g, g->chunk_size, tab);
		if (ft_put_max_on_the_top(b, g) == -1)
			return (-1);
	}
	if (ft_put_max_on_the_top(b, g) == -1)
		return (-1);
	while (lst_size(*b) > 0)
		ft_push(b, a, PA, g);
	ft_free((void **)&tab);
	return (0);
}
