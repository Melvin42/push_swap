/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:52:28 by melperri          #+#    #+#             */
/*   Updated: 2021/12/13 22:39:09 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	it_is_new_min(t_list **b, int to_move)
{
	t_list	*tmp;

	tmp = *b;
	while (tmp)
	{
		if (tmp->index < to_move)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	it_is_new_max(t_list **b, int to_move)
{
	t_list	*tmp;

	tmp = *b;
	while (tmp)
	{
		if (tmp->index > to_move)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	can_we_prepare_b(t_list **b, int to_move)
{
	t_list	*tmp;

	tmp = *b;
	while (tmp)
	{
		if (tmp->index < to_move)
		{
			tmp = tmp->next;
		}
		else
			return (1);
	}
	return (0);
}

int	ft_search_old_min(t_list *b, int nbr)
{
	t_list	*tmp;
	int		front;
	int		back;

	tmp = b;
	front = 0;
	back = 0;
	while (tmp && (!(tmp->index != nbr)))
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

int	ft_search_old_max(t_list *b, int nbr)
{
	t_list	*tmp;
	int		front;
	int		back;

	tmp = b;
	front = 0;
	back = 0;
	while (tmp && (!(tmp->index != nbr)))
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

int	ft_prepare_b(t_list **b, int to_move, t_env *g)
{
	int	ref;
	int	*tab;

	tab = ft_list_to_tab(*b);
	if (tab == NULL)
		return (-1);
	if (it_is_new_min(b, to_move) == 1)
	{
		ref = ft_find_max(*b, tab);
		if (ft_search_old_max(*b, ref) == FRONT)
		{
			while ((*b)->index != ref)
				ft_rotate(b, RB, NULL, g);
		}
		else
		{
			while ((*b)->index != ref)
				ft_reverse_rotate(b, RRB, NULL, g);
		}
	}
	else if (it_is_new_max(b, to_move) == 1)
	{
		ref = ft_find_max(*b, tab);
		if (ft_search_old_max(*b, ref) == FRONT)
		{
			while ((*b)->index != ref)
				ft_rotate(b, RB, NULL, g);
		}
		else
		{
			while ((*b)->index != ref)
				ft_reverse_rotate(b, RRB, NULL, g);
		}
	}
	else
	{
		if (ft_search_new_pos(*b, to_move) == FRONT)
		{
			while (!(to_move >= (*b)->index && to_move <= lst_last(*b)->index))
				ft_rotate(b, RB, NULL, g);
		}
		else
			while (!(to_move >= (*b)->index && to_move <= lst_last(*b)->index))
				ft_reverse_rotate(b, RRB, NULL, g);
	}
	free(tab);
	return (0);
}

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

int	ft_create_chunk(t_list **a, t_list **b, t_env *g)
{
	while (lst_size(*b) < g->chunk_size)
	{
		if ((*a)->index >= g->chunk_min && (*a)->index <= g->chunk_max)
		{
			if (lst_size(*b) > 1)
			{
				if (ft_prepare_b(b, (*a)->index, g) == -1)
					return (-1);
				ft_push(a, b, PB, g);
			}
			else
				ft_push(a, b, PB, g);
		}
		else
		{
			if ((*a)->next && *b)
			{
				if (ft_is_next(*b, (*a)->next->index, g) == 1)
					ft_swap_lst(a, SA, NULL, g);
				else
				{
					if (ft_search_next_to_push(*a, g) == FRONT)
						ft_rotate(a, RA, NULL, g);
					else
						ft_reverse_rotate(a, RRA, NULL, g);
				}
			}
			else
			{
				if (ft_search_next_to_push(*a, g) == FRONT)
					ft_rotate(a, RA, NULL, g);
				else
					ft_reverse_rotate(a, RRA, NULL, g);
			}
		}
	}
	return (0);
}

void	ft_put_min_on_the_top(t_list **b, t_env *g)
{
	if (g->chunk_min != 0)
	{
		while ((*b)->index != g->chunk_max - g->chunk_size + 1)
			ft_rotate(b, RB, NULL, g);
	}
	else
		while ((*b)->index != 0)
			ft_rotate(b, RB, NULL, g);
}

int	ft_put_max_on_the_top(t_list **b, t_env *g)
{
	int	ref;
	int	*tab;

	tab = ft_list_to_tab(*b);
	if (tab == NULL)
		return (-1);
	ref = ft_find_max(*b, tab);
	if (ft_search_old_max(*b, ref) == FRONT)
	{
		while ((*b)->index != g->chunk_max)
			ft_rotate(b, RB, NULL, g);
	}
	else
		while ((*b)->index != g->chunk_max)
			ft_reverse_rotate(b, RRB, NULL, g);
	free(tab);
	return (0);
}

int	ft_put_nbr_on_the_top(t_list *a, int nbr)
{
	t_list	*tmp;
	int		front;
	int		back;

	tmp = a;
	front = 0;
	back = 0;
	while (tmp && tmp->index != nbr)
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

int	ft_push_back_in_a(t_list **a, t_list **b, t_env *g, int max)
{
	if (g->chunk_max != max && g->chunk_max != g->chunk_size - 1)
	{
		if (ft_put_nbr_on_the_top(*a, g->chunk_max + 1) == FRONT)
		{
			while ((*a)->index != g->chunk_max + 1)
				ft_rotate(a, RA, NULL, g);
		}
		else
		{
			while ((*a)->index != g->chunk_max + 1)
				ft_reverse_rotate(a, RRA, NULL, g);
		}
	}
	else if (g->chunk_max == g->chunk_size - 1)
	{
		if (ft_put_nbr_on_the_top(*a, g->chunk_size) == FRONT)
		{
			while ((*a)->index != g->chunk_size)
				ft_rotate(a, RA, NULL, g);
		}
		else
		{
			while ((*a)->index != g->chunk_size)
				ft_reverse_rotate(a, RRA, NULL, g);
		}
		if (ft_put_max_on_the_top(b, g) == -1)
			return (-1);
	}
	if (ft_put_max_on_the_top(b, g) == -1)
			return (-1);
	while (lst_size(*b) > 0)
		ft_push(b, a, PA, g);
	return (0);
}

int	ft_chunk(t_list **a, t_list **b, t_env *g)
{
	int	max;

	max = lst_size(*a) - 1;
	g->chunk_nbr = g->test + 2;
	g->chunk_nbr_max = g->chunk_nbr;
	g->chunk_size = (max + 1) / g->chunk_nbr;
	if (g->chunk_nbr > lst_size(*a))
		return (0);
	g->chunk_max = lst_size(*a) - 1;
	g->chunk_min = lst_size(*a) - g->chunk_size;
	while (g->chunk_nbr != 1)
	{
		ft_create_chunk(a, b, g);
		if (ft_push_back_in_a(a, b, g,  max) == -1)
			return (-1);
		g->chunk_max -= g->chunk_size;
		g->chunk_min -= g->chunk_size;
		g->chunk_nbr--;
	}
	g->chunk_min = 0;
	g->chunk_size = g->chunk_max + 1;
	ft_create_chunk(a, b, g);
	if (ft_push_back_in_a(a, b, g, max) == -1)
		return (-1);
	while ((*a)->index != 0)
		ft_rotate(a, RA, NULL, g);
	return (0);
}
