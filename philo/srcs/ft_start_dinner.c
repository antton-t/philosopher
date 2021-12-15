/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_dinner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:57:15 by antton-t          #+#    #+#             */
/*   Updated: 2021/12/10 19:38:35 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo_check(t_ophi *philo)
{
	pthread_mutex_lock(&philo->time);
	if (philo->unite->alive == 0)
	{
		pthread_mutex_unlock(&philo->time);
		return (0);
	}
	pthread_mutex_unlock(&philo->time);
	return (1);
}

void	*eatting(void *arg)
{
	t_ophi	*philo;

	philo = (t_ophi *)arg;
	while (philo->full != 1 && ft_philo_check(philo))
	{
		if (philo->id_philo % 2 == 1)
			ft_go_eat_odd(philo);
		if (philo->id_philo % 2 == 0)
			ft_go_eat_even(philo);
		if (philo->full == 1)
			break ;
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
        pthread_detach(philo->phi[i].phifi);
		if (philo->nb_philo % 2 == 1)
			usleep(1000);
		i++;
	}
}

int	ft_start_dinner(t_philo *philo)
{
	ft_pthread_create(philo);
	if (ft_check_alive(philo) == 0)
		return (0);
	return (1);
}
