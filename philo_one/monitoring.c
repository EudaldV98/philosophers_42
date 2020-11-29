/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:40:49 by jvaquer           #+#    #+#             */
/*   Updated: 2020/11/23 16:36:32 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	kill_philo(t_data *data, t_philo *philo)
{
	int i;

	i = 0;
	while (i < data->philo_nb)
		pthread_detach(philo[i++].thread);
}

void	meals(t_data *data, t_philo *philo)
{
	while (!data->died && ((int)data->meals_max < data->philo_nb))
		usleep(1000);
	if (data->died || ((int)data->meals_max == data->philo_nb))
		kill_philo(data, philo);
	if (!data->died && ((int)data->meals_max == data->philo_nb))
	{
		pthread_mutex_lock(philo->display);
		display_all_meals(data);
		free(philo->display);
	}
}

void	monitoring(t_data *data, t_philo *philo)
{
	if (data->meals_arg)
		meals(data, philo);
	else
	{
		while (!data->died)
			usleep(1000);
		if (data->died)
			kill_philo(data, philo);
	}
}
