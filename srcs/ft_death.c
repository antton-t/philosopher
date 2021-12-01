/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_death.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:50:14 by antton-t          #+#    #+#             */
/*   Updated: 2021/12/01 21:09:18 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_death(t_ophi *philo)
{
	long long	time;

	time = ft_get_time_of_start();
	if (time - philo->last_food_time > philo->unite->time_to_eat)
		return (1);
	return (0);
}
