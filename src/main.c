/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 03:04:36 by melperri          #+#    #+#             */
/*   Updated: 2021/10/09 18:55:49 by melperri         ###   ########.fr       */
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
	int		index;
	t_list	*next;
};

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_write(char *str)
{
	if (ft_strcmp(str, "SA") == 0)
		write(1, "SA\n", 3);
	else if (ft_strcmp(str, "SB") == 0)
		write(1, "SB\n", 3);
	else if (ft_strcmp(str, "SS") == 0)
		write(1, "SS\n", 3);
	else if (ft_strcmp(str, "PA") == 0)
		write(1, "PA\n", 3);
	else if (ft_strcmp(str, "PB") == 0)
		write(1, "PB\n", 3);
	else if (ft_strcmp(str, "RA") == 0)
		write(1, "RA\n", 3);
	else if (ft_strcmp(str, "RB") == 0)
		write(1, "RB\n", 3);
	else if (ft_strcmp(str, "RR") == 0)
		write(1, "RB\n", 3);
	else if (ft_strcmp(str, "RRA") == 0)
		write(1, "RRA\n", 4);
	else if (ft_strcmp(str, "RRB") == 0)
		write(1, "RRB\n", 4);
	else if (ft_strcmp(str, "RRR") == 0)
		write(1, "RRR\n", 4);
}

t_list	*lst_new(int data, int index)
{
	t_list	*new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->data = data;
	new->index = index;
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

void	lst_pop_first(t_list **lst)
{
	t_list	*tmp;

	if (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
}

void	lst_pop_lastst(t_list **lst)
{
	if (*lst)
	{
		free(lst_last(*lst));
		*lst = NULL;
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

int	ft_create_list(t_list **a, int ac, char **av)
{
	int	i;

	i = 0;
	*a = lst_new(ft_atoi(av[++i]), (i - 1));
	if (*a == NULL)
		return (-1);
	while (++i < ac)
	{
		lst_add_back(a, lst_new(ft_atoi(av[i]), (i - 1)));
	}
	print_lst(*a);
	return (0);
}

void	ft_swap_node(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	*lst = (*lst)->next;
	(*lst)->next = tmp;
}

int	ft_push_a(t_list *a, t_list *b)
{
	(void)a;
	(void)b;
	return (0);
}

int	ft_push_b(t_list *a, t_list *b)
{
	(void)a;
	(void)b;
	return (0);
}

t_list	*ft_rotate(t_list **lst)
{
	t_list	*tmp;
	t_list	*new;

	new = (*lst)->next;
	tmp = lst_last(*lst);
	tmp->next = *lst;
	(*lst)->next = NULL;
	return (new);
}

t_list	*ft_reverse_rotate(t_list **lst)
{
	t_list	*tmp;
	t_list	*new;

	new = lst_last(*lst);
	new->next = *lst;	
	tmp = lst_last(*lst);
	tmp = NULL;
	(*lst)->next = NULL;
	return (new);
}

int	ft_swap_both(t_list *a, t_list *b)
{
	(void)a;
	(void)b;
	return (0);
}

int	ft_reverse_rotate_both(t_list *a, t_list *b)
{
	(void)a;
	(void)b;
	return (0);
}

void	ft_case_two(t_list *a)
{
	int	b;

	b = a->next->data;
	if (a->data > b)
		ft_write("RA");
}

void	ft_case_three(t_list *a)
{
	int	b;
	int	c;

	b = a->next->data;
	c = a->next->next->data;
	if (a->data > b && b < c && a->data < c)
		ft_write("SA");
	else if (a->data < b && b > c && a->data > c)
		ft_write("RRA");
	else if (a->data > b && b > c && a->data > c)
	{
		ft_write("RA");
		ft_write("SA");
	}
	else if (a->data < b && b > c && a->data < c)
	{
		ft_write("SA");
		ft_write("RA");
	}
}

void	ft_case_four(t_list *a)
{
	(void)a;
}

void	ft_case_five(t_list *a)
{
	(void)a;
}

int	ft_case_hundred(t_list *a)
{
	(void)a;
	t_list	*b;

	b = malloc(sizeof(*b));
	b = NULL;
	return (0);
}

int	ft_case_five_hundred(t_list *a)
{
	(void)a;
	t_list	*b;

	b = malloc(sizeof(*b));
	b = NULL;
	return (0);
}

int	ft_check_case(t_list *a, int ac)
{
	if (ac == 3)
		ft_case_two(a);
	else if (ac == 4)
		ft_case_three(a);
	else if (ac == 5)
		ft_case_four(a);
	else if (ac == 6)
		ft_case_five(a);
	else if (ac > 5 && ac <= 101)
	{
		if (ft_case_hundred(a) != 0)
			return (-1);
	}
	else if (ac > 101 && ac <= 501)
	{
		if (ft_case_five_hundred(a) != 0)
			return (-1);
	}
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
