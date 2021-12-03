/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:21:24 by antton-t          #+#    #+#             */
/*   Updated: 2021/12/03 18:20:41 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_go_sleep(t_ophi *philo)
{
	philo->action_time = ft_get_time_of_start();
	ft_create_message(philo, 2);
	ft_usleep(philo, 2);
}
