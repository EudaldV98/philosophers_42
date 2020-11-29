/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 11:14:13 by jvaquer           #+#    #+#             */
/*   Updated: 2020/11/25 19:09:39 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	p_take_fork(t_all *all, t_philo *philo)
{
	pthread_mutex_lock(philo->fork1);
	pthread_mutex_lock(philo->fork2);
	pthread_mutex_lock(philo->display);
	display(all, philo, "has taken a fork");
	display(all, philo, "has taken a fork");
	pthread_mutex_unlock(philo->display);
}

void	p_eat(t_all *all, t_philo *philo)
{
	pthread_mutex_lock(all->philo->display);
	display(all, philo, "is eating");
	philo->last_meal = get_curr(all->data->t_start_usec,
								all->data->t_start_sec);
	pthread_mutex_unlock(all->philo->display);
	usleep(all->data->time_to_eat * 1000);
	pthread_mutex_unlock(philo->fork1);
	pthread_mutex_unlock(philo->fork2);
}

void	p_sleep(t_all *all, t_philo *philo)
{
	pthread_mutex_lock(all->philo->display);
	display(all, philo, "is sleeping");
	pthread_mutex_unlock(all->philo->display);
	usleep(all->data->time_to_sleep * 1000);
}

void	p_think(t_all *all, t_philo *philo)
{
	pthread_mutex_lock(all->philo->display);
	display(all, philo, "is thinking");
	pthread_mutex_unlock(all->philo->display);
}
