/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:23:49 by jvaquer           #+#    #+#             */
/*   Updated: 2020/11/25 19:25:38 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		ft_strcmp(const char *str1, const char *str2)
{
	int i;

	i = 0;
	while (str1[i] == str2[i] && str1[i] && str2[i])
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
