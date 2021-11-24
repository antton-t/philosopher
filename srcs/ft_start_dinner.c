/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_dinner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:57:15 by antton-t          #+#    #+#             */
/*   Updated: 2021/11/24 19:52:14 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_start_unlimited_dinner(t_philo *philo)
{
	if (philo->nb_philo % 2 == 0)
		ft_even_unlimited(philo);
	else
		ft_odd_unlimited(philo);
	return (0);	
}

int	ft_start_limited_dinner(t_philo *philo)
{
	int	i;

	i = 0;
	if (philo->nb_philo % 2 == 0)
		ft_even_limited(philo);
	else
		ft_odd_limited(philo);
	return (0);
}

int	ft_start_dinner(t_philo *philo)
{

	if (philo->num_must_eat == -1)
	{
		if (ft_start_unlimited_dinner(philo) == 1)
			return (0);
	}
	else
	{
		if (ft_start_limited_dinner(philo) == 1)
			return (0);
	}
	return (1);
}
