/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 00:57:24 by melperri          #+#    #+#             */
/*   Updated: 2021/12/14 01:02:57 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_prev(t_list *lst, int to_move, t_env *g)
{
	if (to_move == lst->index - 1 && to_move != g->chunk_min - 1)
		return (1);
	else
		return (0);
}

int	ft_is_next(t_list *lst, int to_move, t_env *g)
{
	if (to_move == lst_last(lst)->index + 1 && to_move != g->chunk_min + 1)
		return (1);
	else
		return (0);
}

int	ft_search_next_to_push(t_list *a, t_env *g)
{
	t_list	*tmp;
	int		front;
	int		back;

	tmp = a;
	front = 0;
	back = 0;
	while (tmp && (!(tmp->index >= g->chunk_min && tmp->index <= g->chunk_max)))
	{
		front++;
		tmp = tmp->next;
	}
	back = lst_size(a) - front;
	if (front <= back)
		return (FRONT);
	else
		return (BACK);
}

int	can_we_prepare_b(t_list **b, int to_move)
{
	t_list	*tmp;

	tmp = *b;
	while (tmp)
	{
		if (tmp->index < to_move)
			tmp = tmp->next;
		else
			return (1);
	}
	return (0);
}

int	ft_search_new_pos(t_list *b, int nbr)
{
	t_list	*tmp;
	int		front;
	int		back;

	tmp = b;
	front = 0;
	back = 0;
	while (tmp && (nbr < tmp->index && nbr > lst_last(tmp)->index))
	{
		front++;
		tmp = tmp->next;
	}
	back = lst_size(b) - front;
	if (front <= back)
		return (FRONT);
	else
		return (BACK);
}
