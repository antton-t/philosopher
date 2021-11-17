/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:57:39 by antton-t          #+#    #+#             */
/*   Updated: 2021/11/17 17:28:18 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct p_eater
{
	t_philo	*philo;
}		t_eater;

typedef	struct	p_philo
{
	int	size;
	int	nb_philo;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_must_eat;
	long long	time;
	t_eater	*eater;
}		t_philo;

#endif
