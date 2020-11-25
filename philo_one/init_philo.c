/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 09:32:51 by jvaquer           #+#    #+#             */
/*   Updated: 2020/11/25 19:15:53 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void					start_mutex(const int nb, t_philo *philo)
{
	int					i;

	i = 0;
	while (i < nb)
	{
		if (!(philo[i].fork1 = malloc(sizeof(pthread_mutex_t))))
			return ;
		pthread_mutex_init(philo[i].fork1, NULL);
		i++;
	}
	i = 0;
	while (i < nb)
	{
		if (i == nb - 1)
			philo[i].fork2 = philo[0].fork1;
		else
			philo[i].fork2 = philo[i + 1].fork1;
		i++;
	}
}

void					start_mutex_display(t_philo *philo, const int nb)
{
	int					i;
	pthread_mutex_t		*display;

	i = 0;
	if (!(display = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t))))
		return ;
	pthread_mutex_init(display, NULL);
	while (i < nb)
	{
		philo[i].display = display;
		i++;
	}
}

int						set_philo(const int nb, t_philo *philo)
{
	int					i;

	i = 0;
	start_mutex(nb, philo);
	start_mutex_display(philo, nb);
	while (i < nb)
	{
		philo[i].id = i + 1;
		philo[i].last_meal = 0;
		i++;
	}
	return (1);
}
