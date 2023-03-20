/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:47:33 by romaurel          #+#    #+#             */
/*   Updated: 2023/03/20 16:35:35 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prtl(t_stack *p, char stack)
{
	int i;

	i = 0;
	while (p){
		printf("stack %c -> %d %p\n", stack, p->i, p->nx);
		p = p->nx;
		i++;
	}
	if (!i)
		printf("stack %c -> empty\n", stack);
}

int	main(void){
	t_stack	*a;
	t_stack	*b;
	t_stack	*p;

	a = NULL;
	b = NULL;
	for (int i = 1; i < 50; i++){
		ft_lstadd_back(&a, ft_lstnew(i));
		ft_lstadd_back(&b, ft_lstnew(i + 1));
	}
	p = a;
	for(int u = 0; p; printf("%d\n", u++)){
		pb(&p, &b);
		p = p->nx;
	}
	prtl(a, 'a');
	prtl(b, 'b');
	return (0);
}