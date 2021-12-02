/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:44:33 by antton-t          #+#    #+#             */
/*   Updated: 2021/12/02 18:46:54 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_print_s(t_ophi *philo, int i)
{
	pthread_mutex_lock(&philo->unite->print);
	pthread_mutex_lock(&philo->unite->dead);
	if (i == 0)
		printf("%lld %i has take a fork\n",
			philo->action_time - philo->unite->time, philo->id_philo);
	if (i == 1)
		printf("%lld %i is eating\n",
			philo->action_time - philo->unite->time, philo->id_philo);
	if (i == 2)
		printf("%lld %i is sleeping\n",
			philo->action_time - philo->unite->time, philo->id_philo);
	if (i == 3)
		printf("%lld %i is thinking\n",
			philo->action_time - philo->unite->time, philo->id_philo);
	pthread_mutex_unlock(&philo->unite->print);
	pthread_mutex_unlock(&philo->unite->dead);
	return (0);
}

void	ft_print(int i)
{
	if (i == 1)
		write(1, "Malloc error\n", 13);
}
