/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 00:48:36 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/05 02:59:35 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PH2.h"

void	start_simulation(t_table *table)
{
	table->start_time = get_time();
	create_threads(table);
	join_threads(table);
}

void	create_threads(t_table *table)
{
	int	i;

	i = 0;
	pthread_create(&table->monitor_thread, NULL, monitor_check, table);
	while (i < table->data->nop)
	{
		pthread_create(&table->philo[i].thread_id, NULL, dinner_time,
			&table->philo[i]);
		i++;
	}
}

void	join_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->data->nop)
	{
		pthread_join(table->philo[i].thread_id, NULL);
		i++;
	}
	pthread_join(table->monitor_thread, NULL);
}
