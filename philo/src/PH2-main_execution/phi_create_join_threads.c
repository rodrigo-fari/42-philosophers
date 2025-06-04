/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_create_join_threads.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:28:28 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/04 12:54:38 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PH2.h"

void	create_join_threads(t_global *global, t_philo *philos,
			pthread_t *monitor, t_data *data)
{
	create_threads(global, philos, monitor, data);
	join_threads(philos, data, monitor);
}

void	create_threads(t_global *global, t_philo *philos,
			pthread_t *monitor, t_data *data)
{
	pthread_create(monitor, NULL, &adm_monitor, global);
	int	i;

	i = 0;
	while (i < data->total_philos)
	{
		pthread_create(&philos[i].thread_id, NULL, &ph_dinner_time, &philos[i]);
		ft_usleep(1);
		i++;
	}
}

void	join_threads(t_philo *philos, t_data *data, pthread_t *monitor)
{
	int	i;

	i = 0;
	while (i < data->total_philos)
	{
		pthread_join(philos[i].thread_id, NULL);
		i++;
	}
	pthread_join(*monitor, NULL);
}
