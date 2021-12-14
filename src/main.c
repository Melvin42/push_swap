/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 03:04:36 by melperri          #+#    #+#             */
/*   Updated: 2021/12/14 18:40:03 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_free_all(t_list **a, t_list **b, t_list **lst)
{
	if (a)
		clear_lst(a);
	if (b)
		clear_lst(b);
	if (lst)
		clear_lst(lst);
	return (-1);
}

static int	ft_create_list(t_list **a, int ac, char **av)
{
	int	i;
	int	*tab;

	i = 1;
	*a = lst_new(ft_atoi(av[i]), 0);
	if (*a == NULL)
		return (-1);
	while (++i < ac)
		lst_add_back(a, lst_new(ft_atoi(av[i]), 0));
	tab = ft_list_to_tab_sort(*a);
	if (tab == NULL)
		return (-1);
	ft_free((void **)&tab);
	return (0);
}

static int	ft_search_best_chunk(int *tab)
{
	int	min;
	int	ret;
	int	i;

	i = 0;
	min = tab[i];
	ret = 0;
	while (++i < TEST_NBR)
	{
		if (tab[i] < min && tab[i] != 0)
		{
			min = tab[i];
			ret = i;
		}
	}
	return (ret);
}

static int	ft_program(t_list *a, t_list *b, t_env *g, int ac)
{
	t_list	*lst;

	if (ft_lstcpy(&lst, a) < 0)
		return (ft_free_all(&a, &b, &lst));
	if (ft_check_double(lst) == -1)
		return (ft_free_all(&a, &b, &lst));
	while (g->test < TEST_NBR)
	{
		if (ft_check_case(&a, &b, ac, g) != 0)
			return (ft_free_all(&a, &b, &lst));
		clear_lst(&a);
		if (ft_lstcpy(&a, lst) < 0)
			return (ft_free_all(&a, &b, &lst));
		g->test++;
		g->chunk_size++;
	}
	g->display = 1;
	g->test = ft_search_best_chunk(g->tab_res);
	if (ft_check_case(&a, &b, ac, g) != 0)
		return (ft_free_all(&a, &b, &lst));
	ft_free_all(&a, &b, &lst);
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	t_env	g;

	if (ac == 1)
		write(1, ERROR, sizeof(ERROR));
	else
	{
		ft_memset(&g, 0, sizeof(g));
		a = NULL;
		b = NULL;
		if (ft_check_int_max(av) == -1)
			return (write(1, ERROR, sizeof(ERROR)));
		if (ft_create_list(&a, ac, av) != 0)
			return (ft_free_all(&a, &b, NULL));
		if (ft_check_already_sort(a) == 1)
			return (ft_free_all(&a, &b, NULL));
		ft_program(a, b, &g, ac);
	}
	return (0);
}
