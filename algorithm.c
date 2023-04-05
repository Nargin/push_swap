/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <rxonrgn@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 04:23:23 by romaurel          #+#    #+#             */
/*   Updated: 2023/04/05 04:48:13 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	from_a_to_b(t_stack **a, t_stack **b, int *array, t_var *u)
{
	while (*a)
	{
		if (ft_lstsize(*a) == 1)
			push(a, b, 'b');
		while (ft_lstsize(*b) < u->end - u->start)
		{
			if (!((*a)->i < array[u->end]
				&& (*a)->i >= array[u->start]))
				rotate(a, 'a');
			else
			{
				push(a, b, 'b');
				if ((*b)->i < array[u->median])
					rotate(b, 'b');
			}
		}
		u->start -= u->size;
		if (u->start < 0)
			u->start = 0;
		u->end += u->size;
		if (u->end >= u->t_num)
			u->end = u->t_num - 1;
	}
}

void	from_b_to_a(t_stack **a, t_stack **b, int *array, t_var *u)
{
	u->unorder_num = 0;
	u->max = ft_lstsize(*b) - 1;
	while (*b)
	{
		if ((*b) && find_big_num(*b) == array[u->max])
			check_cases(a, b, array, u);
		else
			check_case2(a, u);
	}
	while (u->unorder_num != 0)
	{
		reverse_rotate(a, 'a');
		u->unorder_num--;
	}
}

void	check_cases(t_stack **a, t_stack **b, int *array, t_var *u)
{
	if ((*b)->i == array[u->max])
	{
		push(b, a, 'a');
		u->max--;
		if ((*a)->nx && (*a)->i > (*a)->nx->i)
		{
			swap(*a, 'a');
			u->max--;
		}
	}
	else if ((*b)->i == array[u->max - 1])
		push(b, a, 'a');
	else
		not_max_num(a, b, u);
}

void	check_case2(t_stack **a, t_var *u)
{
	if (u->unorder_num > 0)
	{
		reverse_rotate(a, 'a');
		u->unorder_num--;
		u->max--;
	}
}

void	not_max_num(t_stack **a, t_stack **b, t_var *u)
{
	if (u->unorder_num == 0 || (*b)->i > ft_lstlast(*a)->i)
	{
		push(b, a, 'a');
		rotate(a, 'a');
		u->unorder_num++;
	}
	else
	{
		if (find_big_num_index(*b, find_big_num(*b)) < ft_lstsize(*b) / 2)
			rotate(b, 'b');
		else
			reverse_rotate(b, 'b');
	}
}
