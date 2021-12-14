/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_on_top.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 01:03:29 by melperri          #+#    #+#             */
/*   Updated: 2021/12/14 13:19:16 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_put_max_on_the_top(t_list **b, t_env *g)
{
	int	*tab;

	tab = ft_list_to_tab(*b);
	if (tab == NULL)
		return (-1);
	if (ft_search_nbr(*b, g->chunk_max, tab) == FRONT)
		while ((*b)->index != g->chunk_max)
			ft_rotate(b, RB, NULL, g);
	else
		while ((*b)->index != g->chunk_max)
			ft_reverse_rotate(b, RRB, NULL, g);
	free(tab);
	return (0);
}
