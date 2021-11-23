/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 13:14:45 by antton-t          #+#    #+#             */
/*   Updated: 2021/11/23 13:47:21 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>
#include <time.h>
#include "struct.h"

int	ft_atoi(char *str);
int	ft_check_parse_argv(char **argv);
long long	ft_get_time_of_start(void);
void	ft_print(int i);
void	ft_start_dinner(t_philo philo);
void	ft_start_philo(char **argv, int argc);

#endif
