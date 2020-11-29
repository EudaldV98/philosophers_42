/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:02:21 by jvaquer           #+#    #+#             */
/*   Updated: 2020/11/18 19:31:03 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int			ft_atoi(const char *str);
int			ft_strcmp(const char *str1, const char *str2);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *s1);
char		*ft_uitoa(unsigned int n);
int			len_nb(unsigned int nb);
char		*ft_strndup(const char *s1, int n);
char		*ft_strjoind(char *s1, char *s2, int param);
char		*ft_strcpy(char *dest, const char *src);

#endif
