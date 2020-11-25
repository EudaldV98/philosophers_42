/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:24:11 by jvaquer           #+#    #+#             */
/*   Updated: 2020/11/15 11:38:35 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char		*ft_strdup(const char *s1)
{
	char *dup;

	if (!(dup = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	ft_strcpy(dup, s1);
	return (dup);
}
