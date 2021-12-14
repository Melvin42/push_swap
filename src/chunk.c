/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:52:28 by melperri          #+#    #+#             */
/*   Updated: 2021/12/14 18:42:44 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_chunk(t_list **a, t_list **b, t_env *g)
{
	int	*tab;

	tab = NULL;
	g->max = lst_size(*a) - 1;
	g->chunk_nbr = g->test + 2;
	g->chunk_nbr_max = g->chunk_nbr;
	g->chunk_size = (g->max + 1) / g->chunk_nbr;
	if (g->chunk_nbr > lst_size(*a))
		return (0);
	g->chunk_max = lst_size(*a) - 1;
	g->chunk_min = lst_size(*a) - g->chunk_size;
	while (g->chunk_nbr != 1)
	{
		ft_create_chunk(a, b, g);
		if (ft_push_back_in_a(a, b, g, g->max) == -1)
			return (-1);
		g->chunk_max -= g->chunk_size;
		g->chunk_min -= g->chunk_size;
		g->chunk_nbr--;
	}
	g->chunk_min = 0;
	g->chunk_size = g->chunk_max + 1;
	ft_create_chunk(a, b, g);
	if (ft_push_back_in_a(a, b, g, g->max) == -1)
		return (-1);
	tab = ft_list_to_tab(*b);
	if (ft_search_nbr(*b, 0, tab) == FRONT)
		while ((*a)->index != 0)
			ft_rotate(a, RA, NULL, g);
	else
		while ((*a)->index != 0)
			ft_reverse_rotate(a, RRA, NULL, g);
	free(tab);
	return (0);
}
