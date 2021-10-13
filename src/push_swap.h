/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:23:57 by melperri          #+#    #+#             */
/*   Updated: 2021/10/13 15:55:57 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

/*	utils.c */
void	ft_write(char *str);
void	ft_swap(int *a, int *b);
int		ft_strcmp(char *s1, char *s2);
int		ft_isspace(int c);
int		ft_isdigit(int c);
int		ft_atoi(const char *nptr);

/*	lst.c	*/
t_list	*lst_new(int data, int index);
void	lst_add_back(t_list **lst, t_list *new);
void	lst_pop_first(t_list **lst);
void	lst_pop_lastst(t_list **lst);

/*	lst_utils.c */
t_list	*lst_last(t_list *lst);
int		lst_size(t_list *lst);
void	print_lst(t_list *lst);
void	clear_lst(t_list **lst);

/*	operations.c */
void	ft_swap_node(t_list **lst);
int		ft_push_a(t_list *a, t_list *b);
int		ft_push_b(t_list *a, t_list *b);
t_list	*ft_rotate(t_list **lst);
t_list	*ft_reverse_rotate(t_list **lst);
int		ft_swap_both(t_list *a, t_list *b);
int		ft_reverse_rotate_both(t_list *a, t_list *b);

/*	cases.c */
void	ft_case_two(t_list *a);
void	ft_case_three(t_list *a);
void	ft_case_four(t_list *a);
int		ft_case_five(t_list *a);
int		ft_case_hundred(t_list *a);
int		ft_case_five_hundred(t_list *a);
int		ft_check_case(t_list *a, int ac);

/*	free.c */
void	ft_free(void **ptr);

/*	ft_search_median.c */
int		ft_search_median(t_list *lst);

#endif
