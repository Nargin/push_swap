/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:47:33 by romaurel          #+#    #+#             */
/*   Updated: 2023/03/23 16:38:05 by romaurel         ###   ########.fr       */
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
	while (!is_sorted(*a))
	{
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
	while (a)
	{
		tab[++i] = a->i;
		a = a->nx;
	}
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - i)
		{
			if (tab[j] > tab[j + 1])
			{
				t = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = t;
			}
			j++;
		}
		i++;
	}
	median = tab[size / 2];
	free(tab);
	return (median);
}

void	algorithm(t_stack **a, t_stack **b)
{
	int	i;

	i = ft_lstsize((*a));
	if (i <= 3)
		three(a);
	(void) b;
	// if (i <= 5)
	ft_printf("%d\n", get_median(*a, i));
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
	prtl(a, 'a');
	return (0);
}