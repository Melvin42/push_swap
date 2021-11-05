/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:27:29 by melperri          #+#    #+#             */
/*   Updated: 2021/11/05 15:09:04 by melperri         ###   ########.fr       */
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
//	printf("tab_min = %d\n", tab[i]);
	while (++i < len)
	{
//	printf("tab_min = %d\n", tab[i]);
		if (ret > tab[i])
			ret = tab[i];
	}
//	printf("\n");
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
//	printf("tab_max = %d\n", tab[i]);
	while (++i < len)
	{
//	printf("tab_max = %d\n", tab[i]);
		if (ret < tab[i])
			ret = tab[i];
	}
//	printf("\n");
	return (ret);
}

void	ft_set_index(t_list *lst, int *tab)
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

int	*ft_sort_tab(int *tab, int len)
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

int	*ft_list_to_tab_sort(t_list *lst)
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

int	*ft_list_to_tab(t_list *list)
{
	t_list	*tmp;
	int		*tab;
	int		i;

	tab = malloc(sizeof(int) * lst_size(list));
	if (tab == NULL)
		return (NULL);
	tmp = list;
	i = 0;
	while (tmp)
	{
		tab[i] = tmp->index;
		i++;
		tmp = tmp->next;
	}
	return (tab);
}
