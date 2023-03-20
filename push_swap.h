/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:20:26 by romaurel          #+#    #+#             */
/*   Updated: 2023/03/20 16:24:00 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack {
	int					i;
	struct s_stack		*nx;
}				t_stack;

/*	lstfunc.c	*/
t_stack	*ft_lstnew(int content);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
int		ft_lstsize(t_stack *lst);

/*	lstdel.c	*/
void	ft_lstdelone(t_stack *lst);
void	ft_lstclear(t_stack **lst);

/*		s.c		*/
void	ss(t_stack **a, t_stack **b);
void	sa(t_stack **a);
void	sb(t_stack **b);

/*		p.c		*/
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

/*		r.c		*/
void	rr(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);

/*		rr.c	*/
void	rrr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);


void	prtl(t_stack *p, char stack);

#endif