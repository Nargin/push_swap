/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:20:26 by romaurel          #+#    #+#             */
/*   Updated: 2023/03/15 19:12:08 by romaurel         ###   ########.fr       */
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

typedef struct s_prog {
	t_stack	*a;
	t_stack	*b;
}				t_prog;

/*	lstfunc.c	*/
t_stack	*ft_lstnew(int content);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);

/*	lstdel.c	*/
void	ft_lstdelone(t_stack *lst);
void	ft_lstclear(t_stack **lst, void (*del)(void *));

#endif
 