/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 03:39:23 by romaurel          #+#    #+#             */
/*   Updated: 2023/04/06 17:06:31 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack_a)
{
	while (stack_a)
	{
		if (stack_a->nx && stack_a->i > stack_a->nx->i)
			return (1);
		stack_a = stack_a->nx;
	}
	return (0);
}

int	is_doublon(char *av[], int ac)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = i;
		while (++j < ac)
			if (ston(av[j]) == ston(av[i]) && j != i)
				return (0);
	}
	return (1);
}

int	*sort_array(t_stack *stack)
{
	size_t	i;
	int		*arr;

	i = 0;
	arr = (int *)malloc(sizeof(int) * (ft_lstsize(stack)));
	while (stack)
	{
		arr[i] = stack->i;
		stack = stack->nx;
		i++;
	}
	bubble_sort(arr, i);
	return (arr);
}

int	ston(const char *str)
{
	int			i;
	int			neg;
	long long	res;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (res * neg < -2147483648 || res * neg > 2147483647)
		return ((void)ft_printf("Error\n"), (void)exit(0), 0);
	return ((int)res * neg);
}
