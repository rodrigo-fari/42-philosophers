/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adm_log_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:09:45 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/02 22:18:12 by rde-fari         ###   ########.fr       */
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

void	adm_check_dinner_time(t_philo *philo)// tem que ser no loop principal
{
	pthread_mutex_lock(&philo->global->all_meals_reached);
	if (philo->global->all_meals_reached)
	{
		pthread_mutex_unlock(&philo->global->simulation_end);
		break ;
	}
	pthread_mutex_unlock(&philo->global->simulation_end);
}

void	adm_meal_count(t_philo *philo)
{
	pthread_mutex_lock(&philo->global->table->meal_lock);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->global->table->meal_lock);
}
