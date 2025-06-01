/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 19:20:52 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/01 19:59:53 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	else
		return (0);
}

bool	verify_number_size(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (ft_atoi(array[i]) != ft_atol(array[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	number_of_philosophers(char **array)
{
	if (ft_atoi(array[1]) == 1)
		return (false);
	return (true);
}

bool	check_minimum_time(char **array)
{
	if (ft_atoi(array[2]) < 60
		|| ft_atoi(array[3]) < 60
		|| ft_atoi(array[4]) < 60)
		return (false);
	return (true);
}
