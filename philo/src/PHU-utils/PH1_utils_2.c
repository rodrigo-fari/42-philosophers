/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing_utils_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 19:20:52 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/02 13:44:51 by rde-fari         ###   ########.fr       */
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
			return (PARSE_ERROR);
		i++;
	}
	return (PARSE_SUCCESS);
}

bool	number_of_philosophers(char **array)
{
	if (ft_atoi(array[1]) == 1)
		return (PARSE_ERROR);
	return (PARSE_SUCCESS);
}

bool	number_of_philosophers_2(char **array)
{
	if (ft_atoi(array[1]) <= 0)
		return (PARSE_ERROR);
	return (PARSE_SUCCESS);
}
