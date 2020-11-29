/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 11:10:28 by jvaquer           #+#    #+#             */
/*   Updated: 2020/11/25 20:49:16 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/philo.h"

unsigned int		get_start(int t)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	if (t)
		return (time.tv_usec);
	return (time.tv_sec);
}

unsigned int		get_curr(unsigned int start_usec, unsigned int start_sec)
{
	struct timeval	curr_time;
	int				time_sec;

	gettimeofday(&curr_time, NULL);
	time_sec = curr_time.tv_sec - start_sec;
	return ((((unsigned int)time_sec * 1000000 + curr_time.tv_usec)
			- start_usec) / 1000);
}
