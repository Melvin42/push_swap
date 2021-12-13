/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:35:32 by melperri          #+#    #+#             */
/*   Updated: 2021/12/13 05:59:21 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_lst(t_list **lst, char *s1, char *s2, t_env *g)
{
	t_list	*tmp;

	tmp = (*lst)->next;
	(*lst)->next = (*lst)->next->next;
	tmp->next = (*lst);
	(*lst) = tmp;
	if (!s2)
	{
		if (g->display == 1)
			ft_write(s1);
		g->tab_res[g->test]++;
	}
}

void	ft_push(t_list **lst1, t_list **lst2, char *str, t_env *g)
{
	t_list	*tmp;

	tmp = *lst1;
	*lst1 = (*lst1)->next;
	lst_add_front(lst2, tmp);
	if (g->display == 1)
		ft_write(str);
	(g->tab_res)[g->test]++;
}

void	ft_rotate(t_list **lst, char *s1, char *s2, t_env *g)
{
	t_list	*tmp;

	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = NULL;
	lst_add_back(lst, tmp);
	if (!s2)
	{
		if (g->display == 1)
			ft_write(s1);
		g->tab_res[g->test]++;
	}
}

void	ft_reverse_rotate(t_list **lst, char *s1, char *s2, t_env *g)
{
	t_list	*tmp;
	t_list	*prev;

	tmp = lst_last(*lst);
	prev = *lst;
	while (prev->next->next)
		prev = prev->next;
	prev->next = NULL;
	tmp->next = *lst;
	*lst = tmp;
	if (!s2)
	{
		if (g->display == 1)
			ft_write(s1);
		g->tab_res[g->test]++;
	}
}

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
