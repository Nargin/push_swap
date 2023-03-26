/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:47:33 by romaurel          #+#    #+#             */
/*   Updated: 2023/03/26 20:36:04 by romaurel         ###   ########.fr       */
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
			if (tab[j] > tab[j + 1] && j + 1 < size)
			{
				t = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = t;
			}
		}
	}
	for (int i = 0; i < size; i++)
		printf("%d\n", tab[i]);
	median = tab[size / 2];
	free(tab);
	return (median);
}

void	five(t_stack **a, t_stack **b)
{
	int	median;
	int	i;

	i = 0;
<<<<<<< HEAD
	median = get_median(*a, ft_lstsize(*a));
	while (i < 2)
=======
	if (ft_lstsize(*a) == 3)
		return ((void)three(a));
	median = get_median(*a, ft_lstsize(*a));
	while (i < 2 && (*a))
>>>>>>> fc1f403c8239c76a1e5fb1e3b99753f976213eae
	{
		if ((*a)->i <= median)
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
<<<<<<< HEAD
	three(a);
=======
	if (i == 0)
		return ;
	if ((*a)->i > (*a)->nx->i)
		sa(a);
	three(a);
	if ((*b) && (*b)->i < (*b)->nx->i)
		sb(b);
>>>>>>> fc1f403c8239c76a1e5fb1e3b99753f976213eae
	while (i--)
		pa(a, b);
}

<<<<<<< HEAD
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

void sort(t_stack **a, t_stack **b, int size)
{
	int	median;
	int i;

	median = get_median(*a, size);
	ft_printf("median = %d\n", median);
	while (find_index(*a, median) != 0)
	{
		if (find_index(*a, median) <= ft_lstsize(*a) / 2)
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
	// sort(a, b, ft_lstsize(*a));


	prtl(*a, 'a');
	prtl(*b, 'b');
}

=======
>>>>>>> fc1f403c8239c76a1e5fb1e3b99753f976213eae
void	algorithm(t_stack **a, t_stack **b)
{
	int	i;

	i = ft_lstsize((*a));
<<<<<<< HEAD
	if (i <= 3)
		three(a);
	if (i <= 5)
		five(a, b);
	else
		sort(a, b, ft_lstsize(*a));
=======
	if (i <= 5)
		five(a, b);
>>>>>>> fc1f403c8239c76a1e5fb1e3b99753f976213eae
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
<<<<<<< HEAD
	ft_lstclear(&a);
	ft_lstclear(&b);
	// prtl(a, 'a');
=======
	// prtl(a, 'a');
	// prtl(b, 'b');
>>>>>>> fc1f403c8239c76a1e5fb1e3b99753f976213eae
	return (0);
}