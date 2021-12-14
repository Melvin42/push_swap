/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 00:27:59 by melperri          #+#    #+#             */
/*   Updated: 2021/12/14 00:28:00 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_both(t_list **a, t_list **b, t_env *g)
{
	ft_swap_lst(a, SA, SB, g);
	ft_swap_lst(b, SA, SB, g);
	if (g->display == 1)
		ft_write(SS);
	g->tab_res[g->test]++;
}

void	ft_rotate_both(t_list **a, t_list **b, t_env *g)
{
	ft_rotate(a, RA, RB, g);
	ft_rotate(b, RA, RB, g);
	if (g->display == 1)
		ft_write(RR);
	g->tab_res[g->test]++;
}

void	ft_reverse_rotate_both(t_list **a, t_list **b, t_env *g)
{
	ft_reverse_rotate(a, RA, RB, g);
	ft_reverse_rotate(b, RA, RB, g);
	if (g->display == 1)
		ft_write(RRR);
	g->tab_res[g->test]++;
}
