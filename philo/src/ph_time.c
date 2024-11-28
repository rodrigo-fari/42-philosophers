/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:16:33 by rde-fari          #+#    #+#             */
/*   Updated: 2024/11/28 17:37:32 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec * 0.001));
}

long	current_time(long time)
{
	if (time > 0)
		return (get_time() - time);
	return (0);
}

long int	get_time2(void)
{
	struct timeval	ftime;
	long int		time;

	time = 0;
	if (gettimeofday(&ftime, NULL))
		return (-1);
	time = (ftime.tv_sec * 1000) + (ftime.tv_usec / 1000);
	return (time);
}

void	ft_usleep(long int miliseconds)
{
	long int	start;

	start = 0;
	start = get_time2();
	while (get_time2() - start < miliseconds)
		usleep(miliseconds / 10);
}
