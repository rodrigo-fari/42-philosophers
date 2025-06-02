/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PH1_utils_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:22:12 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/02 19:42:28 by rde-fari         ###   ########.fr       */
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

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*call;
	size_t			i;

	call = malloc(size * nmemb);
	if (!call)
		return (NULL);
	i = 0;
	while (i < size * nmemb)
	{
		call[i] = 0;
		i++;
	}
	return (call);
}
