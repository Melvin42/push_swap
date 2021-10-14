/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:35:32 by melperri          #+#    #+#             */
/*   Updated: 2021/10/15 00:04:53 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_lst(t_list **lst, char *s1, char *s2)
{
	t_list	*tmp;

	tmp = (*lst)->next;
	(*lst)->next = (*lst)->next->next;
	tmp->next = (*lst);
	(*lst) = tmp;
	if (!s2)
		ft_write(s1);
}

void	ft_push(t_list **lst1, t_list **lst2, char *str)
{
	t_list	*tmp;

	tmp = *lst1;
	*lst1 = (*lst1)->next;
	lst_add_front(&(*lst2), tmp);
	ft_write(str);
}

void	ft_rotate(t_list **lst, char *s1, char *s2)
{
	t_list	*tmp;

	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = NULL;
	lst_add_back(&(*lst), tmp);
	if (!s2)
		ft_write(s1);
}

void	ft_reverse_rotate(t_list **lst, char *s1, char *s2)
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
		ft_write(s1);
}

void	ft_swap_both(t_list **a, t_list **b)
{
	ft_swap_lst(a, SA, SB); 
	ft_swap_lst(b, SA, SB); 
	ft_write(SS);
}

void	ft_rotate_both(t_list **a, t_list **b)
{
	ft_rotate(a, RA, RB); 
	ft_rotate(b, RA, RB); 
	ft_write(RR);
}

void	ft_reverse_rotate_both(t_list **a, t_list **b)
{
	ft_reverse_rotate(a, RA, RB);
	ft_reverse_rotate(b, RA, RB);
	ft_write(RRR);
}
