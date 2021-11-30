/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:30:29 by antton-t          #+#    #+#             */
/*   Updated: 2021/11/29 11:36:18 by antton-t         ###   ########.fr       */
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

int	ft_print_s(t_philo philo, int i, int id)
{
	long long	ti;

	ti = philo.time - philo.phi[id].action_time;
	printf("%lld %i ",ti, philo.phi[id].id_philo);
	if (i == 0)
		write(1, "has taken a fork\n", 17);
	if (i == 1)
		write(1, "is eating\n", 10);
	if (i == 2)
		write (1, "is sleeping\n", 12);
	if (i == 3)
		write (1, "is thinking\n", 12);
	if (i == 4)
	{
		write(1, "died\n", 5);
		return (1);
	}
	return (0);
}

void	ft_print(int i)
{
	if (i == 1)
		write(1, "Malloc error\n", 13);
}
