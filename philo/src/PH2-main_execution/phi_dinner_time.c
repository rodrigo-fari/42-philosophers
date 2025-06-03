/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_dinner_time.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:16:00 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/03 14:56:01 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ph_dinner_time(void *philo_struct)
{
	t_philo	*philo;

	philo = (t_philo *)philo_struct;
	if (philo->global->ready_threads == 1)
	{
		while (true)
		{
			ph_action_think(philo_struct);
			ph_action_take_l_fork(philo_struct);
			ph_action_take_r_fork(philo_struct);
			ph_action_eat(philo_struct);
			adm_meal_count(philo_struct);
			ph_action_putdown_forks(philo_struct);
			ph_action_sleep(philo_struct);
			if (!adm_check_dinner_time(philo_struct))
				break ;
		}
	}
	else
		usleep(1000);
	return (NULL);
}

void	*adm_monitor(void *global_struct)
{
	t_global	*global;
	t_data		*data;

	global = (t_global *)global_struct;
	data = global->table->data;
	printf("Monitor initialized\n");
	adm_is_everyone_ok(global, data);
	printf("monitor task 1 done\n");
	adm_is_everyone_full(global, data);
	printf("monitor task2 done\n");
	global->ready_threads = 1;
	printf("starting simulation\n");
	usleep(1000);
	return (NULL);
}
