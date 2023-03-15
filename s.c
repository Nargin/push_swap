/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:17:39 by romaurel          #+#    #+#             */
/*   Updated: 2023/03/15 17:02:15 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	t_stack	*tp;

	if (!(*a)->nx || !*a)
		return ;
	tp = (*a);
	tp = tp->nx;
	(*a)->nx = tp->nx;
	tp->nx = (*a);
	(*a) = tp;
}

void	sb(t_stack **b)
{
	sa(*b);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(*a);
	sb(*b);
}

int	main(void){
	t_stack	*a;
	t_stack	*p;

	a = ft_lstnew(10);
	ft_lstadd_back(&a, ft_lstnew(9));
	p = a;
	while (p){
		printf("%d\n", p->i);
		p = p->nx;
	}
	sa(&a);
	p = a;
	while (p){
		printf("%d\n", p->i);
		p = p->nx;
	}
	return (0);
}