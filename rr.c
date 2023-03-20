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
}

void	rrb(t_stack **b)
{
	rra(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rra(b);
}