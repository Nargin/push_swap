/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <rxonrgn@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 04:23:18 by romaurel          #+#    #+#             */
/*   Updated: 2023/04/05 04:35:29 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(int *arr, int arr_len)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < arr_len)
	{
		j = 0;
		while (j < arr_len)
		{	
			if ((j + 1 < arr_len) && arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	find_big_num(t_stack *stack)
{
	int	bignum;

	bignum = stack->i;
	stack = stack->nx;
	while (stack)
	{
		if (stack->i > bignum)
			bignum = stack->i;
		stack = stack->nx;
	}
	return (bignum);
}

int	find_small_num(t_stack *stack_a)
{
	int	smallnum;

	smallnum = stack_a->i;
	stack_a = stack_a->nx;
	while (stack_a)
	{
		if (stack_a->i < smallnum)
			smallnum = stack_a->i;
		stack_a = stack_a->nx;
	}
	return (smallnum);
}

int	find_after_smallnum(t_stack *stack_a)
{
	int	smallnum;
	int	aftersmallnum;

	smallnum = find_small_num(stack_a);
	if (stack_a->i == smallnum)
		stack_a = stack_a->nx;
	aftersmallnum = stack_a->i;
	stack_a = stack_a->nx;
	while (stack_a)
	{
		if (stack_a->i < aftersmallnum && stack_a->i != smallnum)
			aftersmallnum = stack_a->i;
		stack_a = stack_a->nx;
	}
	return (aftersmallnum);
}

int	find_big_num_index(t_stack *stack, int max)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->i == max)
			return (i);
		stack = stack->nx;
		i++;
	}
	return (-1);
}
