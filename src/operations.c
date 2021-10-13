/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:35:32 by melperri          #+#    #+#             */
/*   Updated: 2021/10/13 13:36:17 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_node(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	*lst = (*lst)->next;
	(*lst)->next = tmp;
}

int	ft_push_a(t_list *a, t_list *b)
{
	(void)a;
	(void)b;
	return (0);
}

int	ft_push_b(t_list *a, t_list *b)
{
	(void)a;
	(void)b;
	return (0);
}

t_list	*ft_rotate(t_list **lst)
{
	t_list	*tmp;
	t_list	*new;

	new = (*lst)->next;
	tmp = lst_last(*lst);
	tmp->next = *lst;
	(*lst)->next = NULL;
	return (new);
}

t_list	*ft_reverse_rotate(t_list **lst)
{
	t_list	*tmp;
	t_list	*new;

	new = lst_last(*lst);
	new->next = *lst;	
	tmp = lst_last(*lst);
	tmp = NULL;
	(*lst)->next = NULL;
	return (new);
}

int	ft_swap_both(t_list *a, t_list *b)
{
	(void)a;
	(void)b;
	return (0);
}

int	ft_reverse_rotate_both(t_list *a, t_list *b)
{
	(void)a;
	(void)b;
	return (0);
}
