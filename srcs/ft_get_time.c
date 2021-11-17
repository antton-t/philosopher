/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:32:08 by antton-t          #+#    #+#             */
/*   Updated: 2021/11/17 17:57:59 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_get_time_of_start(void)
{
	long long	time_out;
	struct timeval	time;

	gettimeofday(&time, NULL);
	time_out = time.tv_sec * 1000 + time.tv_usec;
	return (time_out);
}

