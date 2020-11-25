/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 10:35:29 by jvaquer           #+#    #+#             */
/*   Updated: 2020/11/25 19:41:44 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void				*killer(void *all)
{
	t_all			*a;
	int				curr_time;

	a = (t_all *)all;
	usleep(a->data->time_to_die * 1000);
	curr_time = get_curr(a->data->t_start_usec, a->data->t_start_sec);
	if (a->philo->alive &&
		curr_time - a->philo->last_meal >= a->data->time_to_die)
	{
		sem_wait(a->philo->display);
		a->data->died = true;
		display(a, a->philo, "is dead");
		exit(1);
	}
	return (NULL);
}

void				philo_fork(t_all *all, t_philo *philo)
{
	int				i;
	pthread_t		death;

	i = 0;
	while (!all->data->died &&
		(!all->data->meals_arg || i < all->data->meals_nb))
	{
		pthread_detach(death);
		pthread_create(&death, NULL, &killer, all);
		p_take_fork(all, philo);
		p_eat(all, philo);
		p_sleep(all, philo);
		p_think(all, philo);
		i++;
	}
	pthread_detach(death);
	if (all->data->died)
		exit(1);
	if (all->data->meals_arg && i == all->data->meals_nb)
		all->data->meals_max++;
	exit(2);
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
		philo[i].pid = fork();
		if (philo[i].pid == 0)
			philo_fork(all, &philo[i]);
		usleep(10);
		i++;
	}
	return (1);
}

int					main(int ac, char **av)
{
	t_data	*data;
	t_philo	*philo;
	t_all	*all;

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
	free(philo);
	free(data);
	free(all);
	return (0);
}
