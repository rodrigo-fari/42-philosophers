/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_action_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:43:49 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/04 12:54:27 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PH2.h"

void	ph_action_putdown_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	log_manager(philo, "has put down forks");

}

void	ph_action_sleep(t_philo *philo)
{
	log_manager(philo, "is sleeping");
	ft_usleep(philo->data->tts * 1);
}
