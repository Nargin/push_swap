/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:17:39 by romaurel          #+#    #+#             */
/*   Updated: 2023/03/15 19:12:00 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	int	temp;

	if (!(*a)->nx || !*a)
		return ;
	temp = (*a)->i;
	(*a)->i = (*a)->nx->i;
	(*a)->nx->i = temp;
}

void	sb(t_stack **b)
{
	sa(b);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*t;

	if (!*b)
		return ;
	t = (*b)->nx;
	ft_lstadd_back(a, ft_lstnew((*b)->i));
	ft_lstdelone((*b));
	(*b) = t;
}

int	main(void){
	t_prog	p;

	p.a = ft_lstnew(10);
	p.b = ft_lstnew(1);
	printf("a: %d b: %d\n", p.a->i, p.b->i);
	pa(&p.a, &p.b);
	printf("a: %d b: %d\n", p.a->i, p.b->i);
	return (0);
}