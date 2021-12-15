/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:52:55 by antton-t          #+#    #+#             */
/*   Updated: 2021/12/10 21:19:08 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_ophi	*ft_init_philo(t_philo *philo)
{
	int	i;
    t_ophi *phi;

	phi = calloc(sizeof(t_ophi), philo->nb_philo);
	i = 0;
	while (i < philo->nb_philo)
	{
		if (phi == NULL)
			return (NULL);
		phi[i].id_philo = i + 1;
		phi[i].meal_left = philo->num_must_eat;
		phi[i].action_time = 0;
		phi[i].last_food_time = ft_get_time_of_start();
		phi[i].full = 0;
		pthread_mutex_init(&(phi[i].fork_left), NULL);
		pthread_mutex_init(&(phi[i].time), NULL);
		if (i != 0 && i != (philo->nb_philo) - 1)
			phi[i].fork_right = &phi[i - 1].fork_left;
		if (i == (philo->nb_philo) - 1)
			phi[i].fork_right = &phi[i - 1].fork_left;
		phi[i].unite = philo;
		i++;
	}
	return (phi);
}

t_philo	*init_philo(char **argv)
{
	t_philo	*out;

	out = calloc(sizeof(t_philo), 1);
	out->size = 0;
	out->alive = 1;
	out->finish = 0;
	out->nb_philo = ft_atoi(argv[1]);
	out->time_to_eat = ft_atoi(argv[3]);
	out->time_to_sleep = ft_atoi(argv[4]);
	out->time_to_die = ft_atoi(argv[2]);
	out->num_must_eat = -1;
	pthread_mutex_init(&(out->print), NULL);
	return (out);
}

void	ft_start_philo(char **argv, int argc)
{
	t_philo	*philo;

	philo = init_philo(argv);
	if (argc == 6)
		philo->num_must_eat = ft_atoi(argv[5]);
    philo->phi = ft_init_philo(philo);
	if (philo->phi == 0)
		ft_print(3);
	philo->phi[0].fork_right = &(philo->phi[philo->nb_philo - 1].fork_left);
	philo->size = argc;
	philo->time = ft_get_time_of_start();
	if (ft_start_dinner(philo) == 0)
		ft_free(philo);
}
