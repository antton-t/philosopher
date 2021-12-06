/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:52:55 by antton-t          #+#    #+#             */
/*   Updated: 2021/12/06 15:38:22 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_philo(t_philo **philo)
{
	int	i;

	(*philo)->phi = calloc(sizeof(t_ophi), (*philo)->nb_philo);
	i = 0;
	while (i < (*philo)->nb_philo)
	{
		if ((*philo)->phi == NULL)
			return (0);
		(*philo)->phi[i].id_philo = i + 1;
		(*philo)->phi[i].meal_left = (*philo)->num_must_eat;
		(*philo)->phi[i].action_time = 0;
		(*philo)->phi[i].last_food_time = ft_get_time_of_start();
		(*philo)->phi[i].full = 0;
		pthread_mutex_init(&((*philo)->phi[i].fork_left), NULL);
		if (i != 0 && i != ((*philo)->nb_philo) - 1)
			(*philo)->phi[i].fork_right = &((*philo)->phi[i - 1].fork_left);
		if (i == ((*philo)->nb_philo) - 1)
			(*philo)->phi[i].fork_right = &((*philo)->phi[i - 1].fork_left);
		(*philo)->phi[i].unite = (*philo);
		i++;
	}
	return (1);
}

t_philo	*init_philo(char **argv)
{
	t_philo	*out;

	out = malloc(sizeof(t_philo));
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
	if (ft_init_philo(&philo) == 0)
		ft_print(3);
	philo->phi[0].fork_right = &(philo->phi[philo->nb_philo - 1].fork_left);
	philo->size = argc;
	philo->time = ft_get_time_of_start();
	if (ft_start_dinner(philo) == 0)
		return ;
		//ft_free(philo);
}
