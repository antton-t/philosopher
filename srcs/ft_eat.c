/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:21:08 by antton-t          #+#    #+#             */
/*   Updated: 2021/12/02 16:44:33 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_ophi *philo);

int	ft_go_eat_even(t_ophi *philo)
{
	if (philo->meal_left != 0)
	{
		if (pthread_mutex_lock(&philo->fork_left) == 0)
		{
			philo->action_time = ft_get_time_of_start();
			ft_print_s(philo, 0);
			if (pthread_mutex_lock(philo->fork_right) == 0)
			{
				ft_eat(philo);
				if (pthread_mutex_unlock(philo->fork_right) != 0)
					return (1);
			}
			if (pthread_mutex_unlock(&philo->fork_left) != 0)
				return (1);
		}
	}
	return (0);
}

int	ft_go_eat_odd(t_ophi *philo)
{
	if (philo->meal_left != 0)
	{
		if (pthread_mutex_lock(philo->fork_right) == 0)
		{
			philo->action_time = ft_get_time_of_start();
			ft_print_s(philo, 0);
			if (pthread_mutex_lock(&philo->fork_left) == 0)
			{
				ft_eat(philo);
				if (pthread_mutex_unlock(&philo->fork_left) != 0)
					return (1);
			}
			if (pthread_mutex_unlock(philo->fork_right) != 0)
				return (1);
		}
	}
	return (0);
}

void	ft_eat(t_ophi *philo)
{
	philo->action_time = ft_get_time_of_start();
	ft_print_s(philo, 0);
	ft_get_action_time(&philo);
	ft_print_s(philo, 1);
	philo->last_food_time = philo->action_time;
	if (philo->unite->size == 6)
		philo->meal_left --;
	ft_usleep(philo, 1);
}
