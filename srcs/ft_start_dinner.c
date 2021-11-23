/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_dinner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:57:15 by antton-t          #+#    #+#             */
/*   Updated: 2021/11/23 13:51:42 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_start_unlimited_dinner(t_philo philo)
{

}

void	ft_start_limited_dinner(t_philo philo)
{

}

void	ft_start_dinner(t_philo philo)
{
	if (philo.num_must_eat == -1)
		ft_start_unlimited_dinner(philo);
	else
		ft_start_limited_dinner(philo);
}
