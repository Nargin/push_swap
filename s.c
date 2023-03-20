/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:17:39 by romaurel          #+#    #+#             */
/*   Updated: 2023/03/16 15:47:22 by romaurel         ###   ########.fr       */
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
