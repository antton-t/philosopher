/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:31:14 by antton-t          #+#    #+#             */
/*   Updated: 2021/12/10 21:59:34 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_philo(t_ophi *philo)
{
    int	i;

    i = 1;
    while (i < philo->unite->nb_philo)
    {
        free(&philo[i]);
        i++;
    }
}

void	ft_free(t_philo *philo)
{
    int	i;

    i = 0;
    usleep(100);
	if (philo->nb_philo == 1)
	{
		pthread_mutex_destroy(&(philo)->phi[i].fork_left);
		pthread_mutex_destroy(&(philo)->phi[i].time);
	}
	while (i < philo->nb_philo)
	{
		pthread_mutex_destroy(&(philo)->phi[i].fork_left);
		pthread_mutex_destroy(&(philo)->phi[i].time);
		i++;
	}
	free(philo->phi);
	pthread_mutex_destroy(&(philo)->print);
	free(philo);
}
