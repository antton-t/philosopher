/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:52:55 by antton-t          #+#    #+#             */
/*   Updated: 2021/11/23 18:27:58 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	init_philo(void)
{
	t_philo	out;

	out.size = 0;
	out.nb_philo = 0;
	out.time_to_eat = 0;
	out.time_to_sleep = 0;
	out.time_to_die = 0;
	out.num_must_eat = -1;
	return (out);
}

void	ft_start_philo(char **argv, int argc)
{
	t_philo	philo;
	int	i;
	int	j;

	j = 0;
	i = 1;
	philo = init_philo();
	philo.nb_philo = ft_atoi(argv[1]);
	philo.time_to_die = ft_atoi(argv[2]);
	philo.time_to_eat = ft_atoi(argv[3]);
	philo.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo.num_must_eat = ft_atoi(argv[5]);
	philo.size = argc;
	philo.time = ft_get_time_of_start();
	if (ft_start_dinner(philo) == 0)
		ft_free(philo);
}
