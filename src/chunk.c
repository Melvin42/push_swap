/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:52:28 by melperri          #+#    #+#             */
/*   Updated: 2021/11/07 17:58:10 by melperri         ###   ########.fr       */
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
	while (tmp && (!(nbr < tmp->index && nbr > lst_last(tmp)->index)))
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

int	ft_prepare_b(t_list **b, int to_move)
{
	int	ref;
	int	*tab;

	tab = ft_list_to_tab(*b);
	if (tab == NULL)
		return (-1);
	if (it_is_new_min(b, to_move) == 1)
	{
		ref = ft_find_min(*b, tab);
		if (ft_search_old_min(*b, ref) == FRONT)
		{
			while ((*b)->index > ref)
				ft_rotate(b, RB, NULL);
		}
		else
		{
			while ((*b)->index > ref)
				ft_rotate(b, RRB, NULL);
		}
	}
	else if (it_is_new_max(b, to_move) == 1)
	{
		ref = ft_find_min(*b, tab);
		if (ft_search_old_max(*b, ref) == FRONT)
		{
			while ((*b)->index > ref)
				ft_rotate(b, RB, NULL);
		}
		else
		{
			while ((*b)->index > ref)
				ft_rotate(b, RRB, NULL);
		}
	}
	else
	{
		if (ft_search_new_pos(*b, to_move) == FRONT)
		{
			while (!(to_move < (*b)->index && to_move > lst_last(*b)->index))
			{
				ft_rotate(b, RB, NULL);
			}
		}
		else
			while (!(to_move < (*b)->index && to_move > lst_last(*b)->index))
			{
				ft_rotate(b, RRB, NULL);
			}
	}
	free(tab);
	return (0);
}

int	ft_is_prev(t_list *lst, int to_move, int chunk_min)
{
	if (to_move == lst->index - 1 && to_move != chunk_min - 1)
		return (1);
	else
		return (0);
}

int	ft_is_next(t_list *lst, int to_move, int chunk_min)
{
	if (to_move == lst_last(lst)->index + 1 && to_move != chunk_min + 1)
		return (1);
	else
		return (0);
}

int	ft_search_next_to_push(t_list *a, int chunk_max, int chunk_min)
{
	t_list	*tmp;
	int		front;
	int		back;

	tmp = a;
	front = 0;
	back = 0;
	while (tmp && (!(tmp->index >= chunk_min && tmp->index <= chunk_max)))
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

int	ft_create_chunk(t_list **a, t_list **b, int chunk_max, int chunk_min, int i)
{
	(void)i;
	while (lst_size(*b) < CHUNK_SIZE)
	{
		if ((*a)->index >= chunk_min && (*a)->index <= chunk_max)
		{
			if (lst_size(*b) > 1)
			{
				if (ft_prepare_b(b, (*a)->index) == -1)
					return (-1);
				ft_push(a, b, PB);
			}
			else
				ft_push(a, b, PB);
		}
		else
		{
			if ((*a)->next && *b)
			{
				if (ft_is_prev(*b, (*a)->next->index, chunk_min) == 1)
				{
					ft_swap_lst(a, SA, NULL);
				}
				else
				{
					if (ft_search_next_to_push(*a, chunk_max, chunk_min) == FRONT)
						ft_rotate(a, RA, NULL);
					else
						ft_rotate(a, RRA, NULL);
				}
			}
			else
			{
				if (ft_search_next_to_push(*a, chunk_max, chunk_min) == FRONT)
					ft_rotate(a, RA, NULL);
				else
					ft_rotate(a, RRA, NULL);
			}
		}
	}
	return (0);
}

void	ft_put_min_on_the_top(t_list **b, int chunk_min, int chunk_max)
{
	if (chunk_min != 0)
	{
		while ((*b)->index != chunk_max - CHUNK_SIZE + 1)
		{
			ft_rotate(b, RB, NULL);
		}
	}
	else
		while ((*b)->index != 0)
		{
			ft_rotate(b, RB, NULL);
		}
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

void	ft_push_back_in_a(t_list **a, t_list **b, int chunk_max, int chunk_min, int max)
{
	if (chunk_max != max && chunk_max != CHUNK_SIZE - 1)
	{
		if (ft_put_nbr_on_the_top(*a, chunk_max - CHUNK_SIZE - 1) == FRONT)
		{
			while ((*a)->index != chunk_max - CHUNK_SIZE - 1)
			{
				ft_rotate(a, RA, NULL);
			}
		}
		else
		{
			while ((*a)->index != chunk_max - CHUNK_SIZE - 1)
			{
				ft_rotate(a, RRA, NULL);
			}
		}
	}
	else if (chunk_max == CHUNK_SIZE - 1)
	{
		if (ft_put_nbr_on_the_top(*a, max) == FRONT)
		{
			while ((*a)->index != max)
			{
				ft_rotate(a, RA, NULL);
			}
		}
		else
		{
			while ((*a)->index != max)
			{
				ft_rotate(a, RRA, NULL);
			}
		}
		ft_put_min_on_the_top(b, chunk_min, chunk_max);
	}
	ft_put_min_on_the_top(b, chunk_min, chunk_max);
	while (lst_size(*b) > 0)
		ft_push(b, a, PB);
}

int	ft_chunk(t_list **a, t_list **b)
{
	int	max;
	int	chunk_max;
	int	chunk_min;

	max = lst_size(*a) - 1;
	chunk_max = lst_size(*a) - 1;
	chunk_min = chunk_max - (chunk_max / CHUNK_NBR);
	ft_create_chunk(a, b, chunk_max, chunk_min, 20);
	ft_push_back_in_a(a, b, chunk_max, chunk_min, max);
	chunk_max -= CHUNK_SIZE;
	chunk_min -= CHUNK_SIZE;
	ft_create_chunk(a, b, chunk_max, chunk_min, 40);
	ft_push_back_in_a(a, b, chunk_max, chunk_min, max);
	chunk_max -= CHUNK_SIZE;
	chunk_min -= CHUNK_SIZE;
	ft_create_chunk(a, b, chunk_max, chunk_min, 60);
	ft_push_back_in_a(a, b, chunk_max, chunk_min, max);
	chunk_max -= CHUNK_SIZE;
	chunk_min -= CHUNK_SIZE;
	ft_create_chunk(a, b, chunk_max, chunk_min, 80);
	ft_push_back_in_a(a, b, chunk_max, chunk_min, max);
	chunk_max -= CHUNK_SIZE;
	chunk_min -= CHUNK_SIZE;
	ft_create_chunk(a, b, chunk_max, chunk_min, 100);
	ft_push_back_in_a(a, b, chunk_max, chunk_min, max);
	while ((*a)->index != max)
		ft_rotate(a, RA, NULL);
	return (0);
}
