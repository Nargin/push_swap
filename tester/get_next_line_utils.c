/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:11:09 by romaurel          #+#    #+#             */
/*   Updated: 2023/04/05 17:01:35 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int	ft_strchr(char *s, char c)
{
	int	i;

	i = -1;
	if (!s)
		return (0);
	while (s && s[++i])
		if (s[i] == c)
			return (1);
	return (0);
}

char	*ft_strndup(char *s, int len)
{
	int		i;
	char	*cp;

	if (!s || !len)
		return (NULL);
	cp = (char *) malloc((len + 1) * sizeof(char));
	if (!cp)
		return (NULL);
	i = -1;
	while (++i < len)
		cp[i] = s[i];
	cp[i] = 0;
	return (cp);
}
