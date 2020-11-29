/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:40:49 by jvaquer           #+#    #+#             */
/*   Updated: 2020/11/25 19:40:29 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	kill_philo(t_data *data, t_philo *philo)
{
	int i;

	i = 0;
	while (i < data->philo_nb)
		kill(philo[i++].pid, SIGKILL);
}

int		meals(t_data *data, t_philo *philo, int *n, int i)
{
	int	check;

	check = 0;
	waitpid(philo[i].pid, &check, WNOHANG);
	if (WIFEXITED(check))
	{
		if (WEXITSTATUS(check) == 1)
			return (1);
		else if (WEXITSTATUS(check) == 2)
		{
			*n += 1;
			if (*n == data->philo_nb)
				return (2);
		}
	}
	return (0);
}

void	monitoring(t_data *data, t_philo *philo)
{
	int	i;
	int	check;
	int	n;

	i = 0;
	n = 0;
	while (i < data->philo_nb)
	{
		check = meals(data, philo, &n, i);
		if (check == 1 || check == 2)
			break ;
		i++;
		if (i == data->philo_nb)
			i = 0;
	}
	kill_philo(data, philo);
	if (check == 2)
		display_all_meals(data);
}
