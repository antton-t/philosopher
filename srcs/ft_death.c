/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_death.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:50:14 by antton-t          #+#    #+#             */
/*   Updated: 2021/12/03 19:06:05 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_death(t_ophi *philo)
{
	long long	time;

	time = ft_get_time_of_start();
	if (time - philo->last_food_time > philo->unite->time_to_die && philo->meal_left != -1)
    {
        philo->unite->alive = 0;
        return (1);
    }
	return (0);
}
