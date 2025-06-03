/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adm_free_program.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:51:21 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/03 14:22:31 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_program(t_data *data, t_global *global, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < data->total_philos)
	{
		pthread_mutex_destroy(&global->table->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&global->table->write_lock);
	pthread_mutex_destroy(&global->table->meal_lock);
	pthread_mutex_destroy(&global->end_lock);
	free(global->table->forks);
	free(philos);
}
