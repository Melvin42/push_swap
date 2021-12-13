/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 03:04:36 by melperri          #+#    #+#             */
/*   Updated: 2021/12/13 06:07:36 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_free_all(t_list **a, t_list **b, t_list **lst, t_env *g)
{
	(void)g;
	clear_lst(a);
	clear_lst(b);
	clear_lst(lst);
	return (-1);
}

static int	ft_create_list(t_list **a, t_list **b, int ac, char **av)
{
	int	i;
	int	*tab;

	i = 1;
	*b = NULL;
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

//checker les doublons sinon Error\n
//checker les values > int_max sinon Error\n
//ft_list_is_sort
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
		if (tab[i] < min)
		{
			min = tab[i];
			ret = i;
		}
	}
	return (ret);
}

int	main(int ac, char **av)
{
	t_list	*lst;
	t_list	*a;
	t_list	*b;
	t_env	g;

	if (ac == 1)
		write(1, "Error\n", 6);
	else 
	{
		ft_memset(&g, 0, sizeof(g));
		if (ft_create_list(&a, &b, ac, av) != 0)
			return (ft_free_all(&a, &b, &lst, &g));
		if (ft_lstcpy(&lst, a) < 0)
			return (ft_free_all(&a, &b, &lst, &g));
		while (g.test < TEST_NBR)
		{
			if (ft_check_case(&a, &b, ac, &g) != 0)
				return (ft_free_all(&a, &b, &lst, &g));
			clear_lst(&a);
			if (ft_lstcpy(&a, lst) < 0)
				return (ft_free_all(&a, &b, &lst, &g));
			g.test++;
			g.chunk_size++;
		}
		g.display = 1;
		g.test = ft_search_best_chunk(g.tab_res);
		if (ft_check_case(&a, &b, ac, &g) != 0)
			return (ft_free_all(&a, &b, &lst, &g));
//		printf("list A\n");
//		print_lst(a);
//		printf("list B\n");
//		print_lst(b);
		ft_free_all(&a, &b, &lst, &g);
	}
	return (0);
}
