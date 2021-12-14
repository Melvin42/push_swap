/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 00:57:24 by melperri          #+#    #+#             */
/*   Updated: 2021/12/14 13:33:43 by melperri         ###   ########.fr       */
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
	int		*tab;
	int		front;
	int		back;
	int		j = 0;

	front = 0;
	back = lst_size(a) - 1;
	//a mettre dans la fonction mere
	tab = ft_list_to_tab(a);
	while (front < back && (!(tab[front] >= g->chunk_min && tab[front] <= g->chunk_max)))
		front++;
	while (back > 0 && (!(tab[back] >= g->chunk_min && tab[back] <= g->chunk_max)))
	{
		j++;
		back--;
	}
	if (front <= j)
		return (FRONT);
	else
		return (BACK);
}

int	ft_search_new_pos(t_list *b, int nbr, int *tab)
{
	int		front;
	int		back;
	int		size;
	int		j;

	front = 1;
	j = 0;
	size = lst_size(b) - 1;
	back = size;
	if (nbr > tab[0] && nbr < tab[size])
		return (FRONT);
	while (front < size && (!(nbr < tab[front - 1] && nbr > tab[front])))
		front++;
	while (back > 1 && (!(nbr > tab[back] && nbr < tab[back - 1])))
	{
		j++;
		back--;
	}
	if (front <= j)
		return (FRONT);
	else
		return (BACK);
}

/*
9
7
5
*/
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
