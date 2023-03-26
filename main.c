/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:47:33 by romaurel          #+#    #+#             */
/*   Updated: 2023/03/26 22:08:51 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prtl(t_stack *p, char stack)
{
	int i;

	i = 0;
	while (p){
		ft_printf("stack %c -> %d %p\n", stack, p->i, p->nx);
		p = p->nx;
		i++;
	}
	if (!i)
		ft_printf("stack %c -> empty\n", stack);
	ft_printf("----------------------------\n");
}

void	three(t_stack **a)
{
	if (ft_lstsize(*a) == 2)
		sa(a);
	if ((*a)->i > (*a)->nx->i && (*a)->nx->i < (*a)->nx->nx->i
		&& (*a)->i < (*a)->nx->nx->i)
		sa(a);
	else if ((*a)->i > (*a)->nx->i && (*a)->nx->i < (*a)->nx->nx->i
		&& (*a)->i > (*a)->nx->nx->i)
		ra(a);
	else if ((*a)->i < (*a)->nx->i && (*a)->nx->i > (*a)->nx->nx->i
		&& (*a)->i < (*a)->nx->nx->i)
	{
		sa(a);
		ra(a);
	}
	else if ((*a)->i > (*a)->nx->i && (*a)->nx->i > (*a)->nx->nx->i
		&& (*a)->i > (*a)->nx->nx->i)
	{
		ra(a);
		sa(a);
	}
	else if ((*a)->i < (*a)->nx->i && (*a)->nx->i > (*a)->nx->nx->i
		&& (*a)->i > (*a)->nx->nx->i)
		rra(a);
}

int	get_median(t_stack *a, int size)
{
	int	i;
	int	j;
	int	*tab;
	int	median;
	int	t;

	i = -1;
	tab = malloc(size * sizeof(int));
	if (!tab)
		return (0);
	while (a)
	{
		tab[++i] = a->i;
		a = a->nx;
	}
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size - i)
		{
			if (tab[j] > tab[j + 1])
			if (tab[j] > tab[j + 1] && j + 1 < size)
			{
				t = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = t;
			}
		}
	}
	// for (int i = 0; i < size; i++)
		// printf("%d\n", tab[i]);
	median = tab[size / 2];
	free(tab);
	return (median);
}

void	five(t_stack **a, t_stack **b)
{
	int	median;
	int	i;

	i = 0;
	median = get_median(*a, ft_lstsize(*a));
	while (i < 2 && (*a))
	{
		if ((*a)->i < median)
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
	if (i == 0)
		return ;
	three(a);
	if ((*b) && (*b)->i < (*b)->nx->i)
		sb(b);
	while (i--)
		pa(a, b);
}

int	find_index(t_stack *a, int i)
{
	int	index;

	index = 0;
	while (a)
	{
		if (a->i == i)
			return (index);
		a = a->nx;
		index++;
	}
	return (-1);
}

void insertion_sort(t_stack **stack)
{
	t_stack *curr = *stack;
	t_stack *sorted = NULL;

	while (curr != NULL)
	{
		t_stack *next = curr->nx;

		if (sorted == NULL || curr->i < sorted->i)
		{
			curr->nx = sorted;
			sorted = curr;
		}
		else
		{
			t_stack *temp = sorted;
			while (temp->nx != NULL && curr->i > temp->nx->i)
			{
				temp = temp->nx;
			}
			curr->nx = temp->nx;
			temp->nx = curr;
		}
		curr = next;
	}
	*stack = sorted;
}

void sort(t_stack **a, t_stack **b, int size)
{
	int	median;
	int i;

	if (size <= 3 && size > 1)
		return (three(a));
	median = get_median(*a, size);
	// ft_printf("median = %d\n", median);
	while (find_index(*a, median) != 0)
	{
		if (find_index(*a, median) < ft_lstsize(*a) / 2)
			ra(a);
		else
			rra(a);
	}
	i = -1;
	while (++i < size)
	{
		if ((*a)->i <= median)
			pb(a, b);
		else
			ra(a);
	}
	prtl(*a, 'a');
	prtl(*b, 'b');
	sort(a, b, ft_lstsize(*a));
	while (find_index(*a, median) != size - 1){ft_printf("test\n");
		ra(a);}
	// sort(a, b, size - find_index(*a, median) - 1);
	while (b)
		pa(a, b);
	// prtl(*a, 'a');
	// prtl(*b, 'b');
}

void	algorithm(t_stack **a, t_stack **b)
{
	int	i;

	i = ft_lstsize((*a));
	if (i <= 3)
		three(a);
	if (i <= 5)
		five(a, b);
	else
		sort(a, b, ft_lstsize(*a));
}

int	main(int ac, char *av[]){
	t_stack	*a = {NULL};
	t_stack	*b = {NULL};
	int	i;

	i = 0;
	if (ac < 3)
		return (ft_printf("Error : Invalid arguments"));
	if (!is_doublon(av, ac))
		return (ft_printf("Error : Doublon"));
	while (++i < ac)
		ft_lstadd_back(&a, ft_lstnew(atoi(av[i])));
	if (is_sorted(a))
		return (0);
	algorithm(&a, &b);
	// prtl(a, 'a');
	// prtl(b, 'b');
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);
}