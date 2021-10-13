/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:27:04 by melperri          #+#    #+#             */
/*   Updated: 2021/10/13 15:56:11 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lst_new(int data, int index)
{
	t_list	*new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->data = data;
	new->index = index;
	new->next = NULL;
	return (new);
}

void	lst_add_back(t_list **lst, t_list *new)
{
	if (*lst == NULL)
		*lst = new;
	else
		lst_last(*lst)->next = new;
}

void	lst_pop_first(t_list **lst)
{
	t_list	*tmp;

	if (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
}

void	lst_pop_lastst(t_list **lst)
{
	if (*lst)
	{
		free(lst_last(*lst));
		*lst = NULL;
	}
}
