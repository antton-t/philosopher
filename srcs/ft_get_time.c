/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:32:08 by antton-t          #+#    #+#             */
/*   Updated: 2021/12/02 18:42:17 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_get_action_time(t_ophi **philo)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	(*philo)->action_time = time.tv_sec * 1000 + time.tv_usec / 1000;
	return ;
}

long long	ft_get_time_of_start(void)
{
	long long		time_out;
	struct timeval	time;

	gettimeofday(&time, NULL);
	time_out = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (time_out);
}
