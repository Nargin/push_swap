/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstfunc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:40:35 by romaurel          #+#    #+#             */
/*   Updated: 2023/03/14 18:05:46 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_lstnew(int content)
{
	t_stack	*l;

	l = malloc(sizeof(t_stack));
	if (!l)
		return (0);
	l->i = content;
	l->nx = NULL;
	return (l);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*p;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	p = *lst;
	while (p->nx)
		p = p->nx;
	p->nx = new;
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!lst)
		return ;
	new->nx = *lst;
	(*lst) = new;
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->nx)
		lst = lst->nx;
	return (lst);
}

void	ft_lstclear(t_stack **lst, void (*del)(void *))
{
	t_stack	*prev;

	if (!*lst)
		return ;
	while (*lst)
	{
		prev = (*lst)->nx;
		ft_lstdelone((*lst), del);
		(*lst) = prev;
	}
}
