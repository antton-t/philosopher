/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:44:33 by antton-t          #+#    #+#             */
/*   Updated: 2021/12/06 15:50:43 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	add_nb(long long num, char *str)
{
	long long	len;
	long long	nb;

	len = 0;
	nb = num;
	if (num == 0)
	{
		*str = '0';
		return ;
	}
	while (num > 0)
	{
		len++;
		num /= 10;
	}
	num = nb;
	while (len > 0)
	{
		str[--len] = (num % 10) + '0';
		num /= 10;
	}
}

void	ft_strcat(char *src, char *dest)
{
	int		i;
	long	len;

	i = 0;
	len = ft_strlen(src);
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	ft_create_sentence(char *str, int statut, t_ophi *philo, long long time)
{
	int	len;

	add_nb(time, str);
	str[ft_strlen(str)] = ' ';
	add_nb(philo->id_philo, &str[ft_strlen(str)]);
	str[ft_strlen(str)] = ' ';
	len = ft_strlen(str);
	if (statut == 3)
		ft_strcat("is thinking\n", &str[len]);
	else if (statut == 0)
		ft_strcat("has taken fork\n", &str[len]);
	else if (statut == 1)
		ft_strcat("is eating\n", &str[len]);
	else if (statut == 2)
		ft_strcat("is sleeping\n", &str[len]);
}

void	ft_create_message(t_ophi *philo, int i)
{
	char		sentence[100];
	long long	time;

	memset(sentence, 0, 100);
	time = philo->action_time - philo->unite->time;
	pthread_mutex_lock(&philo->unite->print);
	ft_create_sentence(sentence, i, philo, time);
	write (1, sentence, ft_strlen(sentence));
	pthread_mutex_unlock(&philo->unite->print);
}

void	ft_print(int i)
{
	if (i == 1)
		write(1, "Malloc error\n", 13);
}
