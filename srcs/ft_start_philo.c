/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:52:55 by antton-t          #+#    #+#             */
/*   Updated: 2021/11/13 20:56:08 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_start_philo(char **argv, int argc)
{
	t_philo	philo;
	int	i;
	int	j;

	j = 0;
	i = 1;
	philo.tab = (int **)malloc(sizeof(int *) * argc);
	if (philo.tab = NULL)
		ft_print(1);
	philo.tab[argc] = 0;
	while (argv[i])
	{
		philo.tab[j] = ft_atoi(argv[i]);
		j++;
		i++;
	}
}
