/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:57:39 by antton-t          #+#    #+#             */
/*   Updated: 2021/12/01 19:50:02 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

struct p_philo;

typedef struct	p_ophi
{
	int				id_philo;
	pthread_mutex_t	fork_left;
	pthread_mutex_t	*fork_right;
	long long		last_food_time;
	long long		action_time;
	int				meal_left;
	pthread_t		phifi;
	struct p_philo			*unite;

}		t_ophi;
typedef	struct	p_philo
{
	pthread_mutex_t	print;
	pthread_mutex_t dead;
	int				size;
	int				nb_philo;
	int				time_to_eat;
	int				time_to_die;
	int				time_to_sleep;
	int				num_must_eat;
	long long		time;
	int				alive;
	t_ophi	*phi;
}		t_philo;

#endif
