/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 12:01:49 by jvaquer           #+#    #+#             */
/*   Updated: 2020/11/16 12:02:07 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char		*ft_strndup(const char *s1, int n)
{
	char	*ret;
	int		i;

	if (!(ret = (char*)malloc(sizeof(*ret) * (n + 1))))
		return (NULL);
	i = -1;
	while (++i < n)
		ret[i] = s1[i];
	ret[i] = '\0';
	return (ret);
}
