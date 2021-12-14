/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 00:44:30 by melperri          #+#    #+#             */
/*   Updated: 2021/12/14 21:38:01 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_double(t_list *lst)
{
	int	*tab;
	int	size;
	int	i;
	int	j;

	tab = ft_list_to_tab(lst);
	if (tab == NULL)
		return (-1);
	size = lst_size(lst);
	i = 0;
	while (i < size)
	{
		j = i;
		while (++j < size)
		{
			if (tab[i] == tab[j])
			{
				write(1, "Error\n", 6);
				return (-1);
			}
		}
		i++;
	}
	ft_free((void **)&tab);
	return (0);
}
