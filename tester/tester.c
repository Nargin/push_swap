/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:57:07 by romaurel          #+#    #+#             */
/*   Updated: 2023/04/05 18:45:30 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	instructions(char *s, t_stack **stack_a, t_stack **stack_b)
{
		if (!ft_strcmp(s, "sa"))
			b_swap(*stack_a);
		else if (!ft_strcmp(s, "sb"))
			b_swap(*stack_b);
		else if (!ft_strcmp(s, "ss"))
			return ((void)b_swap(*stack_a), (void)b_swap(*stack_b));
		else if (!ft_strcmp(s, "pa"))
			b_push(stack_a, stack_b);
		else if (!ft_strcmp(s, "pb"))
			b_push(stack_b, stack_a);
		else if (!ft_strcmp(s, "ra"))
			b_rotate(stack_a);
		else if (!ft_strcmp(s, "rb"))
			b_rotate(stack_b);
		else if (!ft_strcmp(s, "rr"))
			return ((void)b_rotate(stack_a), (void)b_rotate(stack_b));
		else if (!ft_strcmp(s, "rra"))
			b_reverse_rotate(stack_a);
		else if (!ft_strcmp(s, "rrb"))
			b_reverse_rotate(stack_b);
		else if (!ft_strcmp(s, "rrr"))
		{
			b_reverse_rotate(stack_a);
			b_reverse_rotate(stack_b);
		}
		else
			return ((void)exit(0), (void)ft_printf("Error\n"));
}

int main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*s;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 3 || !is_doublon(av, ac))
		return (ft_printf("Error\n"));
	stack_a = fill_stack_a(ac - 1, av + 1);
	s = get_next_line(0);
	while (s)
	{
		instructions(s, &stack_a, &stack_b);
		free(s);
		s = get_next_line(0);
	}
	if (is_sorted(stack_a) && !stack_b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}