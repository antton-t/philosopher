/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:44:33 by antton-t          #+#    #+#             */
/*   Updated: 2021/12/01 19:44:38 by antton-t         ###   ########.fr       */
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
	long long	ti;

	ti = 0;
	pthread_mutex_lock(&philo->unite->print);
	ti =  philo->action_time - philo->unite->time;
	if (i == 0)
		printf("%lld %i has take a fork\n",ti, philo->id_philo);
	if (i == 1)
		printf("%lld %i is eating\n",ti, philo->id_philo);
	if (i == 2)
		printf("%lld %i is sleeping\n",ti, philo->id_philo);
	if (i == 3)
		printf("%lld %i is thinking\n",ti, philo->id_philo);
	if (i == 4)
	{
		printf("%lld %i died",ti, philo->id_philo);
		return (1);
	}
	pthread_mutex_unlock(&philo->unite->print);
	return (0);
}

void	ft_print(int i)
{
	if (i == 1)
		write(1, "Malloc error\n", 13);
}
