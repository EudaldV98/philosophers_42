/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:40:49 by jvaquer           #+#    #+#             */
/*   Updated: 2020/11/23 17:13:03 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	kill_philo(t_data *data, t_philo *philo)
{
	int i;

	i = 0;
	while (i < data->philo_nb)
		pthread_detach(philo[i++].thread);
}

void	meals(t_data *data, t_philo *philo)
{
	while (!data->died && (data->meals_max < data->philo_nb))
		usleep(1000);
	if (data->died || (data->meals_max == data->philo_nb))
		kill_philo(data, philo);
	if (!data->died && (data->meals_max == data->philo_nb))
	{
		sem_wait(philo->display);
		display_all_meals(data);
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
