/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_dinner_time.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:16:00 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/04 12:52:32 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PH2.h"

void	*ph_dinner_time(void *philo_struct)
{
	t_philo	*philo;

	philo = (t_philo *)philo_struct;
		while (true)
		{
			ph_action_think(philo);
			ph_action_take_forks(philo);
			ph_action_eat(philo);
			adm_meal_count(philo);
			ph_action_putdown_forks(philo);
			ph_action_sleep(philo);
			if (!adm_check_dinner_time(philo))
				break;
		}
	return (NULL);
}

void	*adm_monitor(void *global_struct)
{
	t_global	*global;
	t_data		*data;

	global = (t_global *)global_struct;
	data = global->table->data;
	adm_is_everyone_ok(global, data);
	adm_is_everyone_full(global, data);
	return (NULL);
}
