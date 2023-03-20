/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:27:19 by romaurel          #+#    #+#             */
/*   Updated: 2023/03/20 16:29:41 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!(*b))
		return ;
	tmp = (*b);
	ft_lstadd_front(a, ft_lstnew((*b)->i));
	(*b) = tmp->nx;
	free(tmp);
}

void	pb(t_stack **a, t_stack **b)
{
	pa(b, a);
}