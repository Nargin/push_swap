/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:05:51 by romaurel          #+#    #+#             */
/*   Updated: 2023/03/14 18:14:11 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*nx;
	int		i;
	int		len;

	len = ft_strlen(s2);
	if (!s1)
		return (ft_strndup(s2, len));
	len += ft_strlen(s1);
	nx = malloc(len + 1);
	if (!nx)
		return (free(s1), (char *) NULL);
	i = 0;
	len = 0;
	while (s1[i])
		nx[len++] = s1[i++];
	i = 0;
	while (s2[i])
		nx[len++] = s2[i++];
	nx[len] = 0;
	free(s1);
	return (nx);
}

int	main(void)
{
	char	*str;
	char	*buff;
	int		rfl;

	str = malloc((1025) * sizeof(char));
	if (!str)
		return (NULL);
	rfl = 1;
	while (rfl > 0)
	{
		rfl = read(0, str, 1024);
		str[rfl] = 0;
		buff = ft_strjoin(buff, str);
	}

}