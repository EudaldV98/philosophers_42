/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 12:14:50 by jvaquer           #+#    #+#             */
/*   Updated: 2020/11/25 19:47:14 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include "../head/philo.h"
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <fcntl.h>

typedef struct			s_philo
{
	pthread_t			thread;
	sem_t				*p_fork;
	sem_t				*display;
	int					id;
	int					last_meal;
	bool				alive;
}						t_philo;

int						parse(int ac, char **av, t_data *data);
int						check_data(t_data *data);
int						set_philo(const int nb, t_philo *philo);
void					display(t_all *a, t_philo *philo, char *mssg);
void					p_take_fork(t_all *all, t_philo *philo);
void					p_eat(t_all *all, t_philo *philo);
void					p_sleep(t_all *all, t_philo *philo);
void					p_think(t_all *all, t_philo *philo);
void					display_all_meals(t_data *data);
void					monitoring(t_data *data, t_philo *philo);

#endif
