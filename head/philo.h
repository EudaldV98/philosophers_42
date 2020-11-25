/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 10:33:57 by jvaquer           #+#    #+#             */
/*   Updated: 2020/11/25 19:31:19 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>
# include <string.h>
# include <stdbool.h>
# include "../lib/lib.h"

typedef	struct		s_data
{
	int				philo_nb;
	int				time_to_die;
	int				time_to_sleep;
	int				time_to_eat;
	int				meals_nb;
	int				meals_max;
	int				t_start_sec;
	int				t_start_usec;
	bool			died;
	bool			meals_arg;
}					t_data;

typedef	struct		s_all
{
	struct s_data	*data;
	struct s_philo	*philo;
}					t_all;

void				error_less_args(void);
void				error_more_args(void);
int					get_curr(unsigned int start_usec, unsigned int start_sec);
int					get_start(int t);

#endif
