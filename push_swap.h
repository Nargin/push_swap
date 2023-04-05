/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <rxonrgn@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:20:26 by romaurel          #+#    #+#             */
/*   Updated: 2023/04/05 04:44:13 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"

# define BUFFER_SIZE 1024

typedef struct s_stack {
	int					i;
	struct s_stack		*nx;
}				t_stack;

typedef struct	s_var {
	int	median;
	int	size;
	int	start;
	int	end;
	int	n;
	int	t_num;
	int	unorder_num;
	int	max;
}		t_var;

/* main.c */
void	sort_size(t_stack **a, t_stack **b, int *array, t_var *utils);
void	five(t_stack **a, t_stack **b);
void	three(t_stack **a);

/* utils.c */
void	bubble_sort(int *arr, int arr_len);
int	is_sorted(t_stack *stack_a);
int	is_doublon(char *av[], int ac);
int	*sort_array(t_stack *stack);
int	ston(const char *str);

/* algorithm.c */
void	from_a_to_b(t_stack **a, t_stack **b, int *array, t_var *u);
void	from_b_to_a(t_stack **a, t_stack **b, int *array, t_var *u);
void	not_max_num(t_stack **a, t_stack **b, t_var *u);
void	check_cases(t_stack **a, t_stack **b, int *array, t_var *u);
void	check_case2(t_stack **a, t_var *u);

/* instructions.c */
void	push(t_stack **src, t_stack **dest, char s);
void	reverse_rotate(t_stack **stack, char s);
t_stack	*fill_stack_a(int ac, char **av);
void	rotate(t_stack **stack, char s);
void	swap(t_stack *stack, char s);

/* find_num.c */
void	bubble_sort(int *arr, int arr_len);
int	find_big_num(t_stack *stack);
int	find_small_num(t_stack *stack_a);
int	find_after_smallnum(t_stack *stack_a);
int	find_big_num_index(t_stack *stack, int max);

/* lstdel.c */
void	ft_lstclear(t_stack **lst);
void	ft_lstdelone(t_stack *lst);

/* lstfunc.c */
t_stack	*ft_lstnew(int content);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
int	ft_lstsize(t_stack *lst);

#endif
