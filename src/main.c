/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 03:04:36 by melperri          #+#    #+#             */
/*   Updated: 2021/11/07 17:46:44 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	tab = ft_list_to_tab_sort(*a);
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
//		printf("list A\n");
//		print_lst(a);
//		printf("list B\n");
//		print_lst(b);
		clear_lst(&a);
		clear_lst(&b);
	}
	return (0);
}
