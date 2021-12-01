/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_dinner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:57:15 by antton-t          #+#    #+#             */
/*   Updated: 2021/12/01 21:09:16 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*eatting(void *arg)
{
	t_ophi	*philo;

	philo = (t_ophi *)arg;
	usleep(100);
	philo->last_food_time = ft_get_time_of_start();
	while (philo->meal_left != 0 && philo->unite->alive != 0)
	{
		if (philo->id_philo % 2 == 0)
		{
			if (ft_go_eat_even(philo) == 1)
				philo->unite->alive = 0;
		}
		if (philo->id_philo % 2 == 1)
		{
			if (ft_go_eat_odd(philo) == 1 && philo->unite->alive != 0)
				philo->unite->alive = 0;
		}
printf("alive philo %i\n",philo->unite->alive);
		if (ft_go_sleep(philo) == 0 && philo->unite->alive != 0)
			philo->unite->alive = 0;
	}
	if (philo->unite->alive == 0)
	{
		philo->action_time = ft_get_time_of_start();
		ft_print_s(philo, 3);
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
