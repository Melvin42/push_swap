/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 03:04:36 by melperri          #+#    #+#             */
/*   Updated: 2021/10/15 00:05:57 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_set_index(t_list *lst, int *tab)
{
	t_list	*tmp;
	int	len;
	int	i;

	tmp = lst;
	len = lst_size(lst);
	i = 0;
	while (i < len)
	{
		while (tmp)
		{
			if (tmp->data == tab[i])
				tmp->index = i;
			tmp = tmp->next;
		}
		tmp = lst;
		i++;
	}
}

static int	*ft_sort_tab(int *tab, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		if (tab[i] > tab[j])
		{
			ft_swap(&tab[i], &tab[j]);
			i = 0;
		}
		else
			i++;
	}
	return (tab);
}

static int	*ft_list_to_tab(t_list *lst)
{
	t_list *tmp;
	int	*tab;
	int	len;

	tab = malloc(sizeof(int) * lst_size(lst));
	if (tab == NULL)
		return (NULL);
	tmp = lst;
	len = 0;
	while (tmp)
	{
		tab[len] = tmp->data;
		len++;
		tmp = tmp->next;
	}
	ft_sort_tab(tab, len);
	ft_set_index(lst, tab);
	return (tab);
}

static int	ft_create_list(t_list **a, t_list **b, int ac, char **av)
{
	int	i;
	int	*tab;

	i = 1;
	*b = malloc(sizeof(**b));
	if (*b == NULL)
		return (0);
	*b = NULL;
	*a = lst_new(ft_atoi(av[i]), 0);
	if (*a == NULL)
		return (-1);
	while (++i < ac)
		lst_add_back(a, lst_new(ft_atoi(av[i]), 0));
	tab = ft_list_to_tab(*a);
	if (tab == NULL)
		return (-1);
	ft_free((void **)&tab);
	return (0);
}

//checker les doublons sinon Error\n
//checker les values > int_max sinon Error\n
//ft_list_is_sort
int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	if (ac == 1)
		write(1, "Error\n", 6);
	else 
	{
		if (ft_create_list(&a, &b, ac, av) != 0)
		{
			clear_lst(&a);
			clear_lst(&b);
			return (0);
		}
		if (ft_check_case(&a, &b, ac) != 0)
		{
			clear_lst(&a);
			clear_lst(&b);
			return (0);
		}
		printf("list A\n");
		print_lst(a);
		printf("list B\n");
		print_lst(b);
		clear_lst(&a);
			clear_lst(&b);
	}
	return (0);
}
