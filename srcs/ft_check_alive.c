/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_alive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:36:07 by antton-t          #+#    #+#             */
/*   Updated: 2021/12/02 18:41:18 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_alive(t_philo *philo)
{
	int			i;
	long long	time;

	while (1)
	{
		i = 0;
		while (i < philo->nb_philo)
		{
			if (ft_check_death(&philo->phi[i]) == 1)
			{
				pthread_mutex_lock(&philo->dead);
				pthread_mutex_lock(&philo->print);
				time = ft_get_time_of_start();
				printf("%lld %i died\n", time - philo->time,
					philo->phi[i].id_philo);
				return (1);
			}
			i++;
		}
	}
	return (0);
}
