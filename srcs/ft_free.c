/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:31:14 by antton-t          #+#    #+#             */
/*   Updated: 2021/12/06 16:38:30 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_free_philo(t_ophi *philo)
{
    int i;

    i = 0;
    while (i < philo->unite->nb_philo)
    {
        free(&philo[i]);
        i++;
    }
}

void	ft_free(t_philo *philo)
{
    int i;

    i = 0;
    usleep(100);
    if (philo->nb_philo > 1)
    {
        while (i < philo->nb_philo)
        {
            pthread_join(philo->phi[i].phifi, NULL);
            i++;
        }
    }
    i = 0;
    while (i < philo->nb_philo)
    {
        pthread_mutex_destroy(&(philo)->phi[i].fork_left);
        i++;
    }
    ft_free_philo(philo->phi);
    pthread_mutex_destroy(&(philo)->print);
    free(philo);
}
