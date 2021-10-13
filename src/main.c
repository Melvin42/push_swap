/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 03:04:36 by melperri          #+#    #+#             */
/*   Updated: 2021/10/13 13:44:46 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_create_list(t_list **a, int ac, char **av)
{
	int	i;

	i = 1;
	*a = lst_new(ft_atoi(av[i]), (i - 1));
	if (*a == NULL)
		return (-1);
	while (++i < ac)
	{
		lst_add_back(a, lst_new(ft_atoi(av[i]), (i - 1)));
	}
	print_lst(*a);
	return (0);
}

//checker les doublons sinon Error\n
//checker les values > int_max sinon Error\n
int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	(void)b;
	if (ac == 1)
		write(1, "Error\n", 6);
	else 
	{
		if (ft_create_list(&a, ac, av) != 0)
		{
			clear_lst(&a);
			return (0);
		}
		if (ft_check_case(a, ac) != 0)
		{
			clear_lst(&a);
			return (0);
		}
		clear_lst(&a);
	}
	return (0);
}
