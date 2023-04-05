/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <rxonrgn@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 04:15:23 by romaurel          #+#    #+#             */
/*   Updated: 2023/04/05 04:35:34 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char s)
{
	int	temp;

	if (!stack || !stack->nx)
		return ;
	temp = stack->i;
	stack->i = stack->nx->i;
	stack->nx->i = temp;
	ft_printf("s%c\n", s);
}

void	push(t_stack **src, t_stack **dest, char s)
{
	t_stack	*temp;

	if (!*src)
		return ;
	temp = *src;
	*src = (*src)->nx;
	temp->nx = NULL;
	ft_lstadd_front(dest, temp);
	ft_printf("p%c\n", s);
}

void	rotate(t_stack **stack, char s)
{
	t_stack	*temp;

	if (!*stack || !(*stack)->nx)
		return ;
	temp = *stack;
	*stack = (*stack)->nx;
	temp->nx = NULL;
	ft_lstadd_back(stack, temp);
	ft_printf("r%c\n", s);
}

void	reverse_rotate(t_stack **stack, char s)
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
	ft_printf("rr%c\n", s);
}
