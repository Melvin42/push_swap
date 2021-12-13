/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 05:25:50 by melperri          #+#    #+#             */
/*   Updated: 2021/12/13 05:48:46 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_lstcpy(t_list **dst, t_list *src)
{
	t_list	*tmp;

	*dst = lst_new(src->data, src->index);
	tmp = src->next;;

	while (tmp)
	{
		lst_add_back(dst, lst_new(tmp->data, tmp->index));
		if (lst_last(*dst) == NULL)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}
