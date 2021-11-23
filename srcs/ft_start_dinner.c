/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_dinner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:57:15 by antton-t          #+#    #+#             */
/*   Updated: 2021/11/23 19:44:06 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_start_unlimited_dinner(t_philo philo)
{
	return (1);	
}

int	ft_start_limited_dinner(t_philo philo)
{
	int	i;

	i = 0;
	return (1);
}

int	ft_start_dinner(t_philo philo)
{
	if (philo.num_must_eat == -1)
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
