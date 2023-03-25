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

	if (!a)
		return ;
	tmp = (*a);
	ft_lstadd_back(a, ft_lstnew((*a)->i));
	(*a) = tmp->nx;
	ft_lstdelone(tmp);
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	t_stack	*tmp;

	if (!b)
		return ;
	tmp = (*b);
	ft_lstadd_back(b, ft_lstnew((*b)->i));
	(*b) = tmp->nx;
	ft_lstdelone(tmp);
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}