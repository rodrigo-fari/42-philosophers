/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_routine_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:16:00 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/02 19:41:06 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ph_dinner_time(void *philo_struct)
{
	t_philo *philo;

	philo = (t_philo *)philo_struct;
	while (true)
	{
		ph_action_think();
		ph_action_take_l_fork();
		ph_action_take_r_fork();
		ph_action_eat();
		ph_adm_meal_count();
		ph_action_putdown_forks();
		ph_action_sleep();
		ph_adm_check_dinner_time();
	}
}

void	*adm_dinner_check(void *adm_thread)
{
	
}