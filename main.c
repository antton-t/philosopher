/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 13:05:09 by antton-t          #+#    #+#             */
/*   Updated: 2021/11/13 16:52:04 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	if argc != 5 || argc != 6)
	{
		printf("Error arguments \n");
		return (0);
	}
	else
	{
		if (ft_check_parse_argv(argv) == 0)
		{
			printf("Error parsing argument\n");
			return (0);
		}
		ft_start_philo(argv)
	}
	return (0);
}
