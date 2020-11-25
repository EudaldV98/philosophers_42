/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 11:36:44 by jvaquer           #+#    #+#             */
/*   Updated: 2020/11/25 19:21:29 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static int	ulen(unsigned int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char		*ft_strrev(char *str)
{
	char	swap;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		swap = str[i];
		str[i] = str[j];
		str[j] = swap;
		i++;
		j--;
	}
	return (str);
}

char		*ft_uitoa(unsigned int n)
{
	int		i;
	char	*str;

	if (n == 0)
		return (ft_strdup("0"));
	if (!(str = malloc(sizeof(char) * (ulen(n) + 1))))
		return (NULL);
	i = 0;
	while (n != 0)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	str[i] = '\0';
	str = ft_strrev(str);
	return (str);
}
