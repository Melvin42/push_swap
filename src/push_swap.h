/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:23:57 by melperri          #+#    #+#             */
/*   Updated: 2021/12/13 20:34:37 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define SA "sa"
# define SB "sb"
# define SS "ss"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"
# define FRONT 1
# define BACK 2
# define CHUNK_NBR 5
# define CHUNK_SIZE 20
# define TEST_NBR 15

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_list	t_list;

struct	s_list
{
	int		data;
	int		index;
	t_list	*next;
};

typedef struct s_env {
	int		chunk_size;
	int		chunk_nbr;
	int		chunk_nbr_max;
	int		chunk_max;
	int		chunk_min;
	int		tab_res[TEST_NBR];
	int		test;
	int		display;
} t_env;

/*	utils.c */
void	ft_write(char *str);
void	ft_swap(int *a, int *b);
int		ft_strcmp(char *s1, char *s2);
int		ft_isspace(int c);
int		ft_isdigit(int c);
int		ft_atoi(const char *nptr);
void	*ft_memset(void *s, int c, size_t n);

/*	lst.c	*/
t_list	*lst_new(int data, int index);
void	lst_add_front(t_list **lst, t_list *new);
void	lst_add_back(t_list **lst, t_list *new);
void	lst_pop_first(t_list **lst);
void	lst_pop_lastst(t_list **lst);

/*	lst_utils.c */
t_list	*lst_last(t_list *lst);
int		lst_size(t_list *lst);
void	print_lst(t_list *lst);
void	clear_lst(t_list **lst);
int		ft_lstcpy(t_list **dst, t_list *src);

/*	operations.c */
void	ft_swap_lst(t_list **lst, char *s1, char *s2, t_env *g);
void	ft_push(t_list **lst1, t_list **lst2, char *str, t_env *g);
void	ft_rotate(t_list **lst, char *s1, char *s2, t_env *g);
void	ft_reverse_rotate(t_list **lst, char *s1, char *s2, t_env *g);
void	ft_swap_both(t_list **a, t_list **b, t_env *g);
void	ft_reverse_rotate_both(t_list **a, t_list **b, t_env *g);

/*	cases.c */
void	ft_case_two(t_list *a);
void	ft_case_three(t_list **a, t_env *g);
void	ft_case_four(t_list **a, t_list **b, t_env *g);
void	ft_case_five(t_list **a, t_list **b, t_env *g);
int		ft_case_hundred(t_list **a, t_list **b);
int		ft_case_five_hundred(t_list **a, t_list **b);
int		ft_check_case(t_list **a, t_list **b, int ac, t_env *g);

/*	free.c */
void	ft_free(void **ptr);

/*	ft_search_median.c */
int		ft_search_median(t_list *lst);

/*	ft_chunk.c */
int		ft_chunk(t_list **a, t_list **b, t_env *g);

/*	sort.c */

/*	tab.c */
int		ft_find_min(t_list *lst, int *tab);
int		ft_find_max(t_list *lst, int *tab);
void	ft_set_index(t_list *lst, int *tab);
int		*ft_sort_tab(int *tab, int len);
int		*ft_list_to_tab_sort(t_list *lst);
int		*ft_list_to_tab(t_list *list);

#endif
