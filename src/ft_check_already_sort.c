/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_already_sort.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:42:34 by melperri          #+#    #+#             */
/*   Updated: 2021/12/14 18:39:01 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_already_sort(t_list *a)
{
	t_list	*tmp;
	int		i;

	tmp = a;
	i = tmp->index;
	while (tmp->next && i < tmp->next->index)
	{
		tmp = tmp->next;
		i = tmp->index;
	}
	if (i == lst_last(a)->index)
		return (1);
	else
		return (0);
}
