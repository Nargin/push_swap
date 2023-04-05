/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_instrucs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:12:05 by romaurel          #+#    #+#             */
/*   Updated: 2023/04/05 20:33:42 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_swap(t_stack *stack)
{
	int	temp;

	if (!stack || !stack->nx)
		return ;
	temp = stack->i;
	stack->i = stack->nx->i;
	stack->nx->i = temp;
}

void	b_push(t_stack **src, t_stack **dest)
{
	t_stack	*temp;

	if (!*src)
		return ;
	temp = *src;
	*src = (*src)->nx;
	temp->nx = NULL;
	ft_lstadd_front(dest, temp);
}

void	b_rotate(t_stack **stack)
{
	t_stack	*temp;

	if (!*stack || !(*stack)->nx)
		return ;
	temp = *stack;
	*stack = (*stack)->nx;
	temp->nx = NULL;
	ft_lstadd_back(stack, temp);
}

void	b_reverse_rotate(t_stack **stack)
{	
	t_stack	*temp;

	if (!*stack || !(*stack)->nx)
		return ;
	temp = *stack;
	while (temp->nx->nx)
		temp = temp->nx;
	temp->nx->nx = *stack;
	*stack = temp->nx;
	temp->nx = NULL;
}