/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:52:55 by antton-t          #+#    #+#             */
/*   Updated: 2021/11/25 16:46:14 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_philo(t_philo **philo)
{
	int	i;

	i = 0;
	while (i < (*philo)->nb_philo)
	{
		(*philo)->phi = calloc(sizeof(t_ophi) , (*philo)->nb_philo);
		if ((*philo)->phi == NULL)
			return (0);
		(*philo)->phi[i].id_philo = i + 1;
		(*philo)->phi[i].alive = 1;
		(*philo)->phi[i].meal_left = (*philo)->num_must_eat;
		pthread_mutex_init(&((*philo)->phi[i].fork_left), NULL);
		pthread_mutex_init(&((*philo)->phi[i].fork_right), NULL);
		i++;
	}
	return (1);
}

t_philo	*init_philo(char **argv)
{
	t_philo	*out;

	out = malloc(sizeof(t_philo));
	out->size = 0;
	out->nb_philo = ft_atoi(argv[1]);
	out->time_to_eat = ft_atoi(argv[3]);
	out->time_to_sleep = ft_atoi(argv[4]);
	out->time_to_die = ft_atoi(argv[2]);
	out->num_must_eat = -1;
	return (out);
}

void	ft_start_philo(char **argv, int argc)
{
	t_philo	*philo;
	int	i;
	int	j;

	j = 0;
	i = 1;

	philo = init_philo(argv);
	if (ft_init_philo(&philo) == 0)
		ft_print(3);
	if (argc == 6)
		philo->num_must_eat = ft_atoi(argv[5]);
	philo->size = argc;
	philo->time = ft_get_time_of_start();
	if (ft_start_dinner(philo) == 0)
		ft_free(philo);
}
