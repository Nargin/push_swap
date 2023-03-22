/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:17:39 by romaurel          #+#    #+#             */
/*   Updated: 2023/03/22 15:35:32 by romaurel         ###   ########.fr       */
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
	write (1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	int	temp;

	if (!(*b)->nx || !*b)
		return ;
	temp = (*b)->i;
	(*b)->i = (*b)->nx->i;
	(*b)->nx->i = temp;
	write (1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}
