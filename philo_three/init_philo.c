/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 09:32:51 by jvaquer           #+#    #+#             */
/*   Updated: 2020/11/25 13:27:47 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int					set_philo(int nb, t_philo *philo)
{
	int				i;
	sem_t			*p_fork;
	sem_t			*display;

	i = 0;
	sem_unlink("p_fork");
	sem_unlink("display");
	p_fork = sem_open("p_fork", O_CREAT, 0666, nb);
	display = sem_open("display", O_CREAT, 0666, 1);
	while (i < nb)
	{
		philo[i].id = i + 1;
		philo[i].last_meal = 0;
		philo[i].p_fork = p_fork;
		philo[i].display = display;
		i++;
	}
	return (1);
}
