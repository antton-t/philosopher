/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 13:14:45 by antton-t          #+#    #+#             */
/*   Updated: 2021/12/01 19:56:17 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <time.h>
#include "struct.h"

int	ft_atoi(char *str);
int	ft_check_parse_argv(char **argv);
long long	ft_get_time_of_start(void);
void	ft_print(int i);
int	ft_start_dinner(t_philo *philo);
void	ft_start_philo(char **argv, int argc);
void	ft_free(t_philo *philo);
int	ft_strlen(char *str);
int	ft_print_s(t_ophi *philo, int i);
int	ft_go_sleep(t_ophi *philo);
int	ft_go_eat_odd(t_ophi *philo);
int	ft_go_eat_even(t_ophi *philo);
void	ft_get_action_time(t_ophi **philo);
int	ft_check_alive(t_ophi *philo);
void	ft_usleep(t_ophi *philo, int i);
int	ft_check_death(t_ophi *philo);

#endif
