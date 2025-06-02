/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:09:45 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/02 19:13:26 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	log_manager(t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->global->table->write_lock);
	if (!philo->global->simulation_end)
		printf("%lu %d $s\n", philo->data->start_time, philo->id, message);
	pthread_mutex_unlock(&philo->global->table->write_lock);
}
