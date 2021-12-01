/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:05:32 by antton-t          #+#    #+#             */
/*   Updated: 2021/12/01 19:05:44 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_ft_itoa(long *val, int *i, int *sign, int n)
{
	if (n < 0)
	{
		*val = - (long)n;
		*i = 2;
		*sign = -1;
	}
	else
	{
		*val = n;
		*i = 1;
		*sign = 0;
	}
}

void	len_ft_itoa(long val, int *i)
{
	val /= 10;
	while (val > 0)
	{
		val /= 10;
		(*i)++;
	}
}

char	*ft_itoa(int n)
{
	int		i;
	long	val;
	int		sign;
	char	*s;

	init_ft_itoa(&val, &i, &sign, n);
	len_ft_itoa(val, &i);
	s = malloc(sizeof(*s) * i + 1);
	if (!s)
		return (NULL);
	s[i] = '\0';
	if (n < 0)
		val = - (long)n;
	else
		val = n;
	while (i-- + sign)
	{
		s[i] = (val % 10) + '0';
		val /= 10;
	}
	if (sign == -1)
		s[0] = '-';
	return (s);
}
