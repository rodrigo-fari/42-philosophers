/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:51:21 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/05 14:20:19 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PH2.h"

void	free_program(t_global *global)
{
	int	i;

	pthread_mutex_destroy(global->table->dead_philo_lock);
	pthread_mutex_destroy(global->table->msg_lock);
	i = 0;
	while (i < global->data->nop)
	{
		pthread_mutex_destroy(global->table->philo[i].meal_lock);
		pthread_mutex_destroy(global->table->philo[i].last_meal_lock);
		free(global->table->philo[i].meal_lock);
		free(global->table->philo[i].last_meal_lock);
		i++;
	}
	i = -1;
	while (++i < global->data->nop)
		pthread_mutex_destroy(&global->table->forks[i]);
	free(global->table->forks);
	free(global->table->philo);
	free(global->table->msg_lock);
	free(global->table->dead_philo_lock);
	free(global->data);
	free(global->table);
	free(global);
}
