/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:14:43 by jvaquer           #+#    #+#             */
/*   Updated: 2020/11/25 19:25:58 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void				*ft_nmemcpy(void *dst, void *src, unsigned int n)
{
	unsigned char	*t_dst;
	unsigned char	*t_src;

	t_dst = (unsigned char *)dst;
	t_src = (unsigned char *)src;
	while (t_dst - (unsigned char*)dst < n)
	{
		*t_dst = *t_src;
		t_dst++;
		t_src++;
	}
	return (t_dst);
}

char				*ft_strjoind(char *s1, char *s2, int param)
{
	char			*s_new;
	char			*s;

	if (!(s = (char*)malloc(sizeof(char)
	* ((ft_strlen(s1) + ft_strlen(s2) + 1)))))
		return (NULL);
	s_new = s;
	if (s1 || s2)
	{
		s_new = ft_nmemcpy(s_new, s1, ft_strlen(s1));
		s_new = ft_nmemcpy(s_new, s2, ft_strlen(s2));
	}
	*s_new = '\0';
	if (param == 1)
		free(s1);
	if (param == 2)
		free(s2);
	if (param == 3)
	{
		free(s1);
		free(s2);
	}
	return (s);
}
