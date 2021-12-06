/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:45:06 by antton-t          #+#    #+#             */
/*   Updated: 2021/12/06 15:57:53 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_go_think(t_ophi *philo)
{
	philo->action_time = ft_get_time_of_start();
	ft_create_message(philo, 3);
}

void	ft_usleep(t_ophi *philo, int i)
{
	long long	tmp;
	long long	tmp2;
	long long	tmp3;
	long long	time_ref;

	tmp2 = 0;
	time_ref = ft_get_time_of_start();
	if (i == 1)
		tmp = philo->unite->time_to_eat;
	if (i == 2)
		tmp = philo->unite->time_to_sleep;
	while (tmp2 < tmp)
	{
		tmp3 = ft_get_time_of_start();
		tmp2 = tmp3 - time_ref;
		usleep(100);
	}
}
