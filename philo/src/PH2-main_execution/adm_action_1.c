/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adm_action_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:09:45 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/03 14:49:02 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	log_manager(t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->global->table->write_lock);
	if (!philo->global->simulation_end)
		printf("%lu %d %s\n", philo->data->start_time, philo->id, message);
	pthread_mutex_unlock(&philo->global->table->write_lock);
}

bool	adm_check_dinner_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->global->simulation_end_lock);
	if (philo->global->all_meals_reached == 1)
	{
		pthread_mutex_unlock(&philo->global->simulation_end_lock);
		return (false) ;
	}
	pthread_mutex_unlock(&philo->global->simulation_end_lock);
	return (true);
}

void	adm_meal_count(t_philo *philo)
{
	pthread_mutex_lock(&philo->global->table->meal_lock);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->global->table->meal_lock);
}

long	current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
