/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 00:21:25 by melperri          #+#    #+#             */
/*   Updated: 2021/12/14 00:21:58 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_min(t_list *lst, int *tab)
{
	int	i;
	int	ret;
	int	len;

	i = 0;
	len = lst_size(lst);
	ret = tab[i];
	while (++i < len)
	{
		if (ret > tab[i])
			ret = tab[i];
	}
	return (ret);
}

int	ft_find_max(t_list *lst, int *tab)
{
	int	i;
	int	ret;
	int	len;

	i = 0;
	len = lst_size(lst);
	ret = tab[i];
	while (++i < len)
	{
		if (ret < tab[i])
			ret = tab[i];
	}
	return (ret);
}
