/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:21:08 by antton-t          #+#    #+#             */
/*   Updated: 2021/12/10 17:34:46 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_ophi *philo);

void	ft_go_eat_even(t_ophi *philo)
{
	usleep(100);
	if (philo->meal_left != 0)
	{
		if (pthread_mutex_lock(&philo->fork_left) == 0)
		{
			philo->action_time = ft_get_time_of_start();
			ft_create_message(philo, 0);
			if (pthread_mutex_lock(philo->fork_right) == 0)
			{
				ft_eat(philo);
				if (pthread_mutex_unlock(philo->fork_right) != 0)
					return ;
			}
			if (pthread_mutex_unlock(&philo->fork_left) != 0)
				return ;
		}
	}
	return ;
}

void	ft_go_eat_odd(t_ophi *philo)
{
	if (philo->meal_left != 0)
	{
		if (pthread_mutex_lock(philo->fork_right) == 0)
		{
			philo->action_time = ft_get_time_of_start();
			ft_create_message(philo, 0);
			if (pthread_mutex_lock(&philo->fork_left) == 0)
			{
				ft_eat(philo);
				if (pthread_mutex_unlock(&philo->fork_left) != 0)
					return ;
			}
			if (pthread_mutex_unlock(philo->fork_right) != 0)
				return ;
		}
	}
	return ;
}

void	ft_eat(t_ophi *philo)
{
	philo->action_time = ft_get_time_of_start();
	ft_create_message(philo, 0);
	ft_get_action_time(&philo);
	ft_create_message(philo, 1);
	pthread_mutex_lock(&philo->time);
	philo->last_food_time = philo->action_time;
	pthread_mutex_unlock(&philo->time);
	if (philo->unite->size == 6)
	{
		philo->meal_left --;
		if (philo->meal_left == 0)
			philo->full = 1;
	}
	ft_usleep(philo, 1);
}
