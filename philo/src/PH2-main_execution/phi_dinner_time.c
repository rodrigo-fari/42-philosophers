/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_dinner_time.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:16:00 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/02 22:14:30 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ph_dinner_time(void *philo_struct)
{
	t_philo	*philo;

	philo = (t_philo *)philo_struct;
	while (true)
	{
		ph_action_think(philo_struct);
		ph_action_take_l_fork(philo_struct);
		ph_action_take_r_fork(philo_struct);
		ph_action_eat(philo_struct);
		adm_meal_count(philo_struct);
		ph_action_putdown_forks(philo_struct);
		ph_action_sleep(philo_struct);
		adm_check_dinner_time(philo_struct);
	}
	return (NULL);
}

void	*adm_monitor(void *adm_thread)
{
	adm_is_everyone_ok();
	adm_is_everyone_full();
	usleep(1000);
}
