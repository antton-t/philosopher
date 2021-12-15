/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_death.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:05:27 by antton-t          #+#    #+#             */
/*   Updated: 2021/12/10 20:05:28 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_death(t_ophi *philo)
{
	long long	time;

	pthread_mutex_lock(&philo->time);
	time = ft_get_time_of_start();
	if (time - philo->last_food_time > philo->unite->time_to_die)
	{
		philo->unite->alive = 0;
		pthread_mutex_unlock(&philo->time);
		return (1);
	}
	pthread_mutex_unlock(&philo->time);
	return (0);
}
