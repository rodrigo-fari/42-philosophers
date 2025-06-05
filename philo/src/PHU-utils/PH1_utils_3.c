/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PH1_utils_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:22:12 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/05 00:52:35 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PH2.h"

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

size_t	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (printf("Time error\n"), -1);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_time();
	while (get_time() - start < milliseconds)
		usleep(100);
}
