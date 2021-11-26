/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_dinner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:57:15 by antton-t          #+#    #+#             */
/*   Updated: 2021/11/26 15:33:07 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_eatting(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;

	return (NULL);
}

void	ft_pthread_create(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->nb_philo)
	{
		pthread_create(&philo->phi[i].phifi, NULL, ft_eatting, (void *)philo);
		i++;	
	}
}

int	ft_start_dinner(t_philo *philo)
{
	ft_pthread_create(philo);
	if (philo->num_must_eat == -1)
	{
		//if (ft_start_unlimited_dinner(philo) == 1)
			return (1);
	}
	else
	{
	//	if (ft_start_limited_dinner(philo) == 1)
			return (1);
	}
	return (1);
}
