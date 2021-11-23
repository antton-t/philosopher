/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:57:39 by antton-t          #+#    #+#             */
/*   Updated: 2021/11/23 18:28:19 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct	p_ophi
{
	int	alive;
	int	id_philo;
}		t_ophi;
typedef	struct	p_philo
{
	int	size;
	int	nb_philo;
	int	time_to_eat;
	int	time_to_die;
	int	time_to_sleep;
	int	num_must_eat;
	long long	time;
}		t_philo;

#endif