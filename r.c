/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:31:49 by romaurel          #+#    #+#             */
/*   Updated: 2023/03/22 22:16:35 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*tmp;

	if (!a || !(*a) || !(*a)->nx)
		return ;
	tmp = (*a);
	ft_lstadd_back(a, ft_lstnew((*a)->i));
	(*a) = tmp->nx;
	ft_lstdelone(tmp);
	// write(1, "ra\n", 3);
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	t_stack	*tmp;

	if (!b)
		return ;
	tmp = (*b);
	ft_lstadd_back(b, ft_lstnew((*b)->i));
	(*b) = tmp->nx;
	ft_lstdelone(tmp);
	ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}