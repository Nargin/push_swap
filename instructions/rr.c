/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:10:13 by romaurel          #+#    #+#             */
/*   Updated: 2023/03/20 16:20:40 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!a || !(*a) || !(*a)->nx)
		return ;
	last = *a;
	while (last->nx->nx)
		last = last->nx;
	tmp = last->nx;
	last->nx = NULL;
	tmp->nx = *a;
	*a = tmp;
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!b || !(*b) || !(*b)->nx)
		return ;
	last = *b;
	while (last->nx->nx)
		last = last->nx;
	tmp = last->nx;
	last->nx = NULL;
	tmp->nx = *b;
	*b = tmp;
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}