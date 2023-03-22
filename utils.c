/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:30:10 by romaurel          #+#    #+#             */
/*   Updated: 2023/03/22 15:39:59 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_doublon(char *av[], int ac)
{
	int	i;
	int j;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		while (++j < ac)
			if (atoi(av[j]) == atoi(av[i]) && j != i)
				return (0);
	}
	return (1);
}

int	is_sorted(t_stack *a)
{
	int	i;

	i = a->i;
	a = a->nx;
	while (a)
	{
		if (a->i < i)
			return (0);
		i = a->i;
		a = a->nx;
	}
	return (1);
}