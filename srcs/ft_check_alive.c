/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_alive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:36:07 by antton-t          #+#    #+#             */
/*   Updated: 2021/12/06 16:03:55 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_finish(t_philo *philo)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < philo->nb_philo)
	{
		if (philo->phi[i].full == 1)
			j++;
		if (j == philo->nb_philo)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_alive(t_philo *philo)
{
	int			i;
	long long	time;

	while (philo->finish != 1)
	{
		i = 0;
		while (i < philo->nb_philo)
		{
			if (ft_check_finish(philo) == 1)
			{
				philo->finish = 1;
				break ;
			}
			if (ft_check_death(&philo->phi[i]) == 1)
			{
				pthread_mutex_lock(&philo->print);
				time = ft_get_time_of_start();
				printf("%lld %i died\n", time - philo->time,
					philo->phi[i].id_philo);
                pthread_mutex_unlock(&philo->print);
				return (1);
			}
			i++;
		}
	}
	return (0);
}
