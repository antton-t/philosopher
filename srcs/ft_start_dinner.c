/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_dinner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:57:15 by antton-t          #+#    #+#             */
/*   Updated: 2021/11/30 20:07:38 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*eatting(void *arg)
{
	t_ophi	*philo;

	philo = (t_ophi *)arg;
	while (philo->meal_left != 0 || philo->alive != 0)
	{
		if (ft_go_eat(philo) == 1)
			;
		if (ft_go_sleep(philo) == 1)
			;
		if (philo->alive == 1 && philo->meal_left != 0)
		{
			ft_get_action_time(&philo);
			ft_print_s(philo, 3);
		}
	}
	return (NULL);
}

void	ft_pthread_create(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->nb_philo)
	{
		pthread_create(&philo->phi[i].phifi , NULL, eatting, &philo->phi[i]);
		i += 2;	
	}
	i = 1;
	usleep(2);
	while (i < philo->nb_philo)
	{
		pthread_create(&philo->phi[i].phifi, NULL, eatting, &philo->phi[i]);
		i += 2;	
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
