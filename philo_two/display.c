/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 11:29:15 by jvaquer           #+#    #+#             */
/*   Updated: 2020/11/23 17:16:43 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void				display_all_meals(t_data *data)
{
	char			*time;
	char			*dot;
	int				current_time;

	current_time = get_curr(data->t_start_usec, data->t_start_sec);
	dot = "......";
	time = ft_uitoa(current_time);
	write(1, dot, ft_strlen(dot) - len_nb(current_time));
	write(1, time, ft_strlen(time));
	free(time);
	write(1, " all meals ate\n", 15);
}

void				display(t_all *a, t_philo *philo, char *mssg)
{
	char			*t;
	char			*id;
	char			*dot;
	char			*str;
	int				curr_t;

	str = NULL;
	curr_t = get_curr(a->data->t_start_usec, a->data->t_start_sec);
	dot = "......";
	t = ft_uitoa(curr_t);
	id = ft_uitoa(philo->id);
	str = ft_strndup(dot, ft_strlen(dot) - len_nb(curr_t));
	str = ft_strjoind(str, t, 3);
	str = ft_strjoind(str, " ", 1);
	str = ft_strjoind(str, id, 3);
	str = ft_strjoind(str, " ", 1);
	str = ft_strjoind(str, mssg, 1);
	str = ft_strjoind(str, "\n", 1);
	write(1, str, ft_strlen(str));
	free(str);
}
