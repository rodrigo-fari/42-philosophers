/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing_utils_3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:22:12 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/02 13:34:53 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	array_len(char **array)
{
	int	len;

	len = 0;
	while (array[len])
		len++;
	return (len);
}

bool	check_minimum_time(char **array)
{
	if (ft_atoi(array[2]) < 60
		|| ft_atoi(array[3]) < 60
		|| ft_atoi(array[4]) < 60)
		return (PARSE_ERROR);
	return (PARSE_SUCCESS);
}
