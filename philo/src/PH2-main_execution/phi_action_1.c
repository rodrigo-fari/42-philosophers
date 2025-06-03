/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_action_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:43:38 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/03 14:16:56 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_action_think(t_philo *philo)
{
	log_manager(philo, "is thinking");
}

void	ph_action_take_l_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	log_manager(philo, "has taken a fork");
}

void	ph_action_take_r_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	log_manager(philo, "has taken a fork");
}

void	ph_action_eat(t_philo *philo)
{
	log_manager(philo, "is eating");
	philo->last_meal_time = current_time();
	usleep(philo->data->tte * 1000);
}
