/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PH2_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 02:21:42 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/05 03:06:29 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PH2.h"

void	log_msg(t_philo *philo, int state)
{
	pthread_mutex_lock(philo->table->msg_lock);
	pthread_mutex_lock(philo->table->dead_philo_lock);
	if (philo->table->dead_philo == false)
	{
		printf("%zi %d ", get_time() - philo->table->start_time, philo->id);
		if (state == FORK_TAKEN)
			printf("has taken a fork\n");
		else if (state == EATING)
			printf("is eating\n");
		else if (state == SLEEPING)
			printf("is sleeping\n");
		else if (state == THINKING)
			printf("is thinking\n");
	}
	else if (state == DEAD)
		printf("%zi %d died\n",
			get_time() - philo->table->start_time, philo->id);
	pthread_mutex_unlock(philo->table->msg_lock);
	pthread_mutex_unlock(philo->table->dead_philo_lock);
}

bool	check_if_dead(t_philo *philo)
{
	bool	is_dead;

	is_dead = false;
	pthread_mutex_lock(philo->table->dead_philo_lock);
	if (philo->table->dead_philo == true)
		is_dead = true;
	pthread_mutex_unlock(philo->table->dead_philo_lock);
	return (is_dead);
}

int	philosopher_status(t_philo *philo)
{
	pthread_mutex_lock(philo->last_meal_lock);
	if (philo->last_meal == 0)
	{
		if (get_time() - philo->table->start_time
			> (size_t) philo->data->ttd)
			return (pthread_mutex_unlock(philo->last_meal_lock),
				phiaction_kill(philo), DEAD);
		pthread_mutex_unlock(philo->last_meal_lock);
	}
	else if (get_time() - philo->last_meal > (size_t)philo->data->ttd)
	{
		return (pthread_mutex_unlock(philo->last_meal_lock),
			phiaction_kill(philo), DEAD);
		pthread_mutex_unlock(philo->last_meal_lock);
	}
	else
		pthread_mutex_unlock(philo->last_meal_lock);
	return (ALIVE);
}

void	phiaction_kill(t_philo *philo)
{
	pthread_mutex_lock(philo->table->dead_philo_lock);
	if (philo->table->dead_philo == false)
	{
		philo->table->dead_philo = true;
		pthread_mutex_unlock(philo->table->dead_philo_lock);
		log_msg(philo, DEAD);
	}
	else
		pthread_mutex_unlock(philo->table->dead_philo_lock);
}
