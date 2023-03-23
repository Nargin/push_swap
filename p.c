/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:27:19 by romaurel          #+#    #+#             */
/*   Updated: 2023/03/23 18:04:30 by romaurel         ###   ########.fr       */
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
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!(*a))
		return ;
	tmp = (*a);
	ft_lstadd_front(b, ft_lstnew((*a)->i));
	(*a) = tmp->nx;
	free(tmp);
	ft_printf("pb\n");
}