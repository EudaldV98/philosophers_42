/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 09:32:51 by jvaquer           #+#    #+#             */
/*   Updated: 2020/11/25 20:54:07 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int					set_philo(int nb, t_philo *philo)
{
	int				i;
	sem_t			*p_fork;
	sem_t			*display;

	i = 0;
	sem_unlink("p_fork");
	sem_unlink("display");
	p_fork = sem_open("p_fork", O_CREAT | O_EXCL, S_IRWXU, nb);
	display = sem_open("display", O_CREAT | O_EXCL, S_IRWXU, 1);
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
