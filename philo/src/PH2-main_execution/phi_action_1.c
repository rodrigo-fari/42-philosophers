/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_action_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:43:38 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/04 12:54:12 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PH2.h"

void	ph_action_think(t_philo *philo)
{
	log_manager(philo, "is thinking");
}

void ph_action_take_forks(t_philo *philo)
{
if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->left_fork);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
	}

}


void	ph_action_eat(t_philo *philo)
{
	log_manager(philo, "is eating");
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal_time = get_time();
	pthread_mutex_unlock(&philo->meal_lock);
	ft_usleep(philo->data->tte * 1);
}
