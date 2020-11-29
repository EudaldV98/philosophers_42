/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 10:35:36 by jvaquer           #+#    #+#             */
/*   Updated: 2020/11/25 19:45:56 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include "../head/philo.h"

typedef struct			s_philo
{
	pthread_t			thread;
	pthread_mutex_t		*fork1;
	pthread_mutex_t		*fork2;
	pthread_mutex_t		*display;
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
