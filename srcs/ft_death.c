/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_death.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:50:14 by antton-t          #+#    #+#             */
/*   Updated: 2021/12/06 17:10:39 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_death(t_ophi *philo)
{
	long long	time;

	time = ft_get_time_of_start();
	pthread_mutex_lock(&philo->time);
	if (time - philo->last_food_time > philo->unite->time_to_die)
    {
		pthread_mutex_unlock(&philo->time);
        philo->unite->alive = 0;
        return (1);
    }
	pthread_mutex_unlock(&philo->time);
	return (0);
}
