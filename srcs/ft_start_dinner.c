/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_dinner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:57:15 by antton-t          #+#    #+#             */
/*   Updated: 2021/12/03 19:04:39 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*eatting(void *arg)
{
	t_ophi	*philo;

	philo = (t_ophi *)arg;
	usleep(10);
	while (philo->meal_left != 0 && philo->unite->alive != 0)
	{
		if (philo->id_philo % 2 == 0)
			ft_go_eat_even(philo);
		if (philo->id_philo % 2 == 1)
			ft_go_eat_odd(philo);
		ft_go_sleep(philo);
		ft_go_think(philo);	
	}
	return (NULL);
}

void	ft_pthread_create(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->nb_philo)
	{
		pthread_create(&philo->phi[i].phifi, NULL, eatting, &philo->phi[i]);
		i += 2;
	}
	i = 1;
	while (i < philo->nb_philo)
	{
		pthread_create(&philo->phi[i].phifi, NULL, eatting, &philo->phi[i]);
		i += 2;
		usleep(10);
	}
}

int	ft_start_dinner(t_philo *philo)
{
	ft_pthread_create(philo);
	if (ft_check_alive(philo) == 1)
		return (0);
	return (1);
}
