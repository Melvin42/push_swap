/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:52:28 by melperri          #+#    #+#             */
/*   Updated: 2021/11/05 15:09:45 by melperri         ###   ########.fr       */
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
		while ((*b)->index > ref)
		{
			ft_rotate(b, RB, NULL);
		}
	}
	else if (it_is_new_max(b, to_move) == 1)
	{
		ref = ft_find_min(*b, tab); 
		while ((*b)->index > ref)
		{
			ft_rotate(b, RB, NULL);
		}
	}
	else
	{
		while (!(to_move < (*b)->index && to_move > lst_last(*b)->index))
		{
			ft_rotate(b, RB, NULL);
		}
	}
	free(tab);
	return (0);
}

int	ft_create_chunk(t_list **a, t_list **b, int chunk_max, int chunk_min, int i)
{
	while (lst_size(*b) < i)
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
			ft_rotate(a, RA, NULL);
		}
	}
	return (0);
}

int	ft_chunk(t_list **a, t_list **b)
{
	int	chunk_max;
	int	chunk_min;

	chunk_max = lst_size(*a) - 1;
	chunk_min = chunk_max - (chunk_max / CHUNK_NBR);
	ft_create_chunk(a, b, chunk_max, chunk_min, 20);
	chunk_max -= CHUNK_SIZE;
	chunk_min -= CHUNK_SIZE;
	ft_create_chunk(a, b, chunk_max, chunk_min, 40);
	chunk_max -= CHUNK_SIZE;
	chunk_min -= CHUNK_SIZE;
	ft_create_chunk(a, b, chunk_max, chunk_min, 60);
	chunk_max -= CHUNK_SIZE;
	chunk_min -= CHUNK_SIZE;
	ft_create_chunk(a, b, chunk_max, chunk_min, 80);
	chunk_max -= CHUNK_SIZE;
	chunk_min -= CHUNK_SIZE;
	ft_create_chunk(a, b, chunk_max, chunk_min, 100);
	return (0);
}
