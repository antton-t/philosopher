/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:21:24 by antton-t          #+#    #+#             */
/*   Updated: 2021/12/01 20:10:24 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_go_sleep(t_ophi *philo)
{
	if (ft_check_death(philo) == 1)
		return (0);
	philo->action_time = ft_get_time_of_start();
	ft_print_s(philo, 2);
	ft_usleep(philo, 2);
	if (ft_check_death(philo) == 1)
		return (0);
	return (1);
}
