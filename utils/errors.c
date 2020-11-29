/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:57:13 by jvaquer           #+#    #+#             */
/*   Updated: 2020/11/25 19:29:42 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/philo.h"

void	error_less_args(void)
{
	write(1, "Error : The program needs 5 or 6 arguments\n", 43);
}

void	error_more_args(void)
{
	write(1, "Error : Too much arguments.", 27);
	write(1, " Please insert 5 min, and 6 max\n", 32);
}
