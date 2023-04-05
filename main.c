/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <rxonrgn@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 03:47:41 by romaurel          #+#    #+#             */
/*   Updated: 2023/04/05 04:49:16 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three(t_stack **a)
{
	if (ft_lstsize(*a) == 2)
		swap(a, 'a');
	if ((*a)->i > (*a)->nx->i && (*a)->nx->i < (*a)->nx->nx->i
		&& (*a)->i < (*a)->nx->nx->i)
		swap(a, 'a');
	else if ((*a)->i > (*a)->nx->i && (*a)->nx->i < (*a)->nx->nx->i
		&& (*a)->i > (*a)->nx->nx->i)
		rotate(a, 'a');
	else if ((*a)->i < (*a)->nx->i && (*a)->nx->i > (*a)->nx->nx->i
		&& (*a)->i < (*a)->nx->nx->i)
	{
		swap(a, 'a');
		rotate(a, 'a');
	}
	else if ((*a)->i > (*a)->nx->i && (*a)->nx->i > (*a)->nx->nx->i
		&& (*a)->i > (*a)->nx->nx->i)
	{
		rotate(a, 'a');
		swap(a, 'a');
	}
	else if ((*a)->i < (*a)->nx->i && (*a)->nx->i > (*a)->nx->nx->i
		&& (*a)->i > (*a)->nx->nx->i)
		reverse_rotate(a, 'a');
}

void	five(t_stack **a, t_stack **b)
{
	int	smallnum;
	int	aftersmallnum;

	smallnum = find_small_num(*a);
	if (ft_lstsize(*a) == 5)
		aftersmallnum = find_after_smallnum(*a);
	else
		aftersmallnum = smallnum;
	while (ft_lstsize(*a) > 3)
	{
		if ((*a)->i == smallnum || (*a)->i == aftersmallnum)
			push(a, b, 'b');
		else
			rotate(a, 'a');
	}
	sort_three(a);
	if ((*b)->nx && (*b)->i < (*b)->nx->i)
		swap(*b, 'b');
	while (*b)
		push(b, a, 'a');
}

void	sort_size(t_stack **a, t_stack **b, int *array, t_var *utils)
{
	if (ft_lstsize(*a) == 3)
		three(a);
	else if (ft_lstsize(*a) <= 5)
		five(a, b);
	else
	{
		utils->t_num = ft_lstsize(*a);
		utils->median = (utils->t_num / 2);
		if (utils->t_num <= 30)
			utils->n = 5;
		else if (utils->t_num <= 150)
			utils->n = 8;
		else
			utils->n = 18;
		utils->size = (utils->t_num / utils->n);
		utils->start = utils->median - utils->size;
		utils->end = utils->median + utils->size;
		from_a_to_b(a, b, array, utils);
		from_b_to_a(a, b, array, utils);
	}
}

void	vortex_void_devourer(t_stack *a, t_stack *b, int *array)
{
	free(array);
	ft_lstclear(&a);
	ft_lstclear(&b);
	return ((void)(1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10));
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_var	utils;
	int	*array;
	int	i;

	if (ac < 3 || is_doublon(av, ac))
		return (ft_printf("Error\n"));
	i = 0;
	while (++i < ac)
		ft_lstadd_back(&a, ft_lstnew(atoi(av[i])));
	b = NULL;
	array = sort_array(a);
	if (!is_sorted(a))
		sort_size(&a, &b, array, &utils);
	vortex_void_devourer(a, b, array);
	return (0);
}
