/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_vars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 01:40:46 by jvaquer           #+#    #+#             */
/*   Updated: 2020/11/25 19:35:42 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int		check_time(const int t, char *s)
{
	if (t <= 0)
	{
		write(1, "Error: ", 7);
		write(1, s, ft_strlen(s));
		write(1, " can't be < 1\n", 14);
		return (0);
	}
	else if (t > 0 && t < 60)
	{
		write(1, "Warning: ", 9);
		write(1, s, ft_strlen(s));
		write(1, " less 60 ms delay may be short.\n", 33);
	}
	return (1);
}

int		check_meals_nb(const int nb)
{
	if (nb <= 0)
	{
		write(1, "Error: ", 7);
		write(1, "[number_of_times_each_philosopher_must_eat]", 43);
		write(1, " can't be < 1\n", 14);
	}
	return (1);
}

int		check_data(t_data *data)
{
	if (data->philo_nb <= 1)
	{
		write(1, "Error: [philosophers number] must be > 1\n", 41);
		return (0);
	}
	else if (data->philo_nb > 200)
	{
		write(1, "Warning: large philosophers number.", 35);
		write(1, " May reduce performance or even crash\n", 37);
	}
	if (!check_time(data->time_to_die, "time_to_die") ||
		!check_time(data->time_to_eat, "time_to_eat") ||
		!check_time(data->time_to_sleep, "time_to_sleep"))
		return (0);
	if (data->meals_arg == true)
		if (!check_meals_nb(data->meals_nb))
			return (1);
	return (1);
}
