/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 11:14:13 by jvaquer           #+#    #+#             */
/*   Updated: 2020/11/25 19:39:19 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	p_take_fork(t_all *all, t_philo *philo)
{
	sem_wait(philo->p_fork);
	sem_wait(philo->p_fork);
	sem_wait(philo->display);
	display(all, philo, "has taken a fork");
	display(all, philo, "has taken a fork");
	sem_post(philo->display);
}

void	p_eat(t_all *all, t_philo *philo)
{
	sem_wait(philo->display);
	display(all, philo, "is eating");
	philo->last_meal = get_curr(all->data->t_start_usec,
								all->data->t_start_sec);
	sem_post(philo->display);
	usleep(all->data->time_to_eat * 1000);
	sem_post(philo->p_fork);
	sem_post(philo->p_fork);
}

void	p_sleep(t_all *all, t_philo *philo)
{
	sem_wait(all->philo->display);
	display(all, philo, "is sleeping");
	sem_post(all->philo->display);
	usleep(all->data->time_to_sleep * 1000);
}

void	p_think(t_all *all, t_philo *philo)
{
	sem_wait(all->philo->display);
	display(all, philo, "is thinking");
	sem_post(all->philo->display);
}
