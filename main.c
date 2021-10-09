/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 03:04:36 by melperri          #+#    #+#             */
/*   Updated: 2021/10/09 16:48:56 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct	s_list t_list;

struct	s_list
{
	int		data;
	t_list	*next;
};

t_list	*lst_new(int data)
{
	t_list	*new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

t_list	*lst_last(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	lst_add_back(t_list **lst, t_list *new)
{
	if (*lst == NULL)
		*lst = new;
	else
		lst_last(*lst)->next = new;
}

int	lst_size(t_list *lst)
{
	t_list	*tmp;
	int	i;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	print_lst(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
}

void	clear_lst(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = NULL;
		*lst = tmp;
	}
}

int	ft_isspace(int c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *nptr)
{
	unsigned long int	res;
	int					sign;

	res = 0;
	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	while (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		res = res * 10 + (*nptr - 48);
		nptr++;
	}
	if (res > LONG_MAX && sign == -1)
		return (0);
	else if (res > LONG_MAX && sign == 1)
		return (-1);
	return (res * sign);
}

int	main(int ac, char **av)
{
	t_list	*new;
	int		i;

	if (ac == 1)
		write(1, "Error\n", 6);
	else 
	{
		new = NULL;
		i = 0;
		new = lst_new(ft_atoi(av[++i]));
		while (++i < ac)
			lst_add_back(&new, lst_new(ft_atoi(av[i])));
		print_lst(new);
		clear_lst(&new);
	}
	return (0);
}
