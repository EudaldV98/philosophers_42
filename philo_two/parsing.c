/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 11:05:08 by jvaquer           #+#    #+#             */
/*   Updated: 2020/11/29 10:24:42 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int		init_data(char **av, t_data *data)
{
	data->philo_nb = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->meals_max = 0;
	if (av[5])
	{
		data->meals_arg = true;
		data->meals_nb = ft_atoi(av[5]);
	}
	else
	{
		data->meals_arg = false;
		data->meals_nb = 0;
	}
	return (0);
}

int		check_args(int ac)
{
	if (ac != 5 && ac != 6)
	{
		if (ac < 5)
			error_less_args();
		else
			error_more_args();
		return (0);
	}
	return (1);
}

int		parse(int ac, char **av, t_data *data)
{
	data->died = false;
	if (check_args(ac))
	{
		init_data(av, data);
		if (!check_data(data))
			return (0);
	}
	else
		return (0);
	return (1);
}
