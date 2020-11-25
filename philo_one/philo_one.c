/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 10:35:29 by jvaquer           #+#    #+#             */
/*   Updated: 2020/11/25 19:16:52 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void				*killer(void *all)
{
	t_all			*a;
	t_data			*data;
	t_philo			*philo;
	int				curr_time;

	a = (t_all *)all;
	data = a->data;
	philo = a->philo;
	usleep(data->time_to_die * 1000);
	curr_time = get_curr(data->t_start_usec, data->t_start_sec);
	if (philo->alive && curr_time - philo->last_meal >= data->time_to_die)
	{
		pthread_mutex_lock(philo->display);
		data->died = true;
		display(a, philo, "is dead");
	}
	return (NULL);
}

void				*philo_thread(void *all)
{
	int				i;
	t_all			*a;
	pthread_t		death;

	a = (t_all *)all;
	a->philo->alive = true;
	i = 0;
	while (!a->data->died && (!a->data->meals_arg || i < a->data->meals_nb))
	{
		pthread_detach(death);
		pthread_create(&death, NULL, &killer, a);
		p_take_fork(a, a->philo);
		p_eat(a, a->philo);
		p_sleep(a, a->philo);
		p_think(a, a->philo);
		i++;
	}
	a->philo->alive = false;
	pthread_detach(death);
	if (a->data->meals_arg && i == a->data->meals_nb)
		a->data->meals_max++;
	return (NULL);
}

int					start_philo(t_all *all, t_data *data, t_philo *philo)
{
	int				i;

	i = 0;
	data->t_start_usec = get_start(1);
	data->t_start_sec = get_start(0);
	while (i < data->philo_nb)
	{
		all[i].philo = &philo[i];
		all[i].data = data;
		if (pthread_create(&philo[i].thread, NULL, &philo_thread, &all[i]))
			return (0);
		usleep(10);
		i++;
	}
	return (1);
}

int					main(int ac, char **av)
{
	t_data			*data;
	t_philo			*philo;
	t_all			*all;

	if (!(data = (t_data *)malloc(sizeof(t_data))))
		return (0);
	if (!parse(ac, av, data))
		return (0);
	if (!(philo = (t_philo *)malloc(sizeof(t_philo) * data->philo_nb)))
		return (0);
	if (!set_philo(data->philo_nb, philo))
		return (0);
	if (!(all = (t_all *)malloc(sizeof(t_all) * (data->philo_nb + 1))))
		return (0);
	start_philo(all, data, philo);
	monitoring(data, philo);
	free(all);
	return (0);
}
