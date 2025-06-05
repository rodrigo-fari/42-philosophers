/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_time_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 02:39:16 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/05 02:52:19 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PH2.h"

void	phiaction_forkon(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		log_msg(philo, FORK_TAKEN);
		pthread_mutex_lock(philo->r_fork);
		log_msg(philo, FORK_TAKEN);
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		log_msg(philo, FORK_TAKEN);
		pthread_mutex_lock(philo->l_fork);
		log_msg(philo, FORK_TAKEN);
	}
}

void	phiaction_forkoff(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
	}
}
