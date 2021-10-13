/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:28:23 by melperri          #+#    #+#             */
/*   Updated: 2021/10/13 15:20:01 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lst_last(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

int	lst_size(t_list *lst)
{
	t_list	*tmp;
	int	i;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	print_lst(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		printf("data = %d | index = %d\n", tmp->data, tmp->index);
		tmp = tmp->next;
	}
}
void	clear_lst(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = NULL;
		*lst = tmp;
	}
}