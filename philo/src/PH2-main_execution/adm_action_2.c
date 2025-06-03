/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adm_action_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 02:10:23 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/03 19:35:54 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	adm_is_everyone_ok(t_global *global, t_data *data)
{
	int		i;
	long	lst_meal;

	i = 0;
	printf("Entrou na funcao adm_is_everyone_ok\n");
	while (true)
	{
		while (i < data->total_philos)
		{
			printf("\n[while cycle][%d]\n\n", i);
			pthread_mutex_lock(&global->table->meal_lock);
			lst_meal = current_time() - global->table->philos[i].last_meal_time; // Corrigido para usar last_meal_time
			if (lst_meal >= data->ttd)
			{
				printf("Entrou no if (indevido)\n");
				pthread_mutex_lock(&global->end_lock);
				global->simulation_end = 1;
				pthread_mutex_unlock(&global->end_lock);
				log_manager(&global->table->philos[i], "died");
				pthread_mutex_unlock(&global->table->meal_lock); // Garantir que o mutex seja liberado
				return;
			}
			pthread_mutex_unlock(&global->table->meal_lock);
			i++;
		}
		usleep(1000); // Adicionado para evitar consumo excessivo de CPU
	}
}

void	adm_is_everyone_full(t_global *global, t_data *data)
{
	int	all_ate_enough;
	int	i;

	all_ate_enough = 1;
	i = 0;
	if (data->max_meals != -1)
	{
		while (i < data->total_philos)
		{
			pthread_mutex_lock(&global->table->meal_lock);
			if (global->table->philos[i].meals_eaten < data->max_meals)
				all_ate_enough = 0;
			pthread_mutex_unlock(&global->table->meal_lock);
			i++;
		}
		if (all_ate_enough)
		{
			pthread_mutex_lock(&global->end_lock);
			global->simulation_end = 1;
			global->all_meals_reached = 1;
			pthread_mutex_unlock(&global->end_lock);
			return ;
		}
	}
}
