/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adm_action_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 02:10:23 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/04 00:34:25 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	adm_is_everyone_ok(t_global *global, t_data *data)
{
	int		i;
	long	lst_meal;

	i = 0;
	while (true)
	{
		pthread_mutex_lock(&global->end_lock);
		if (global->simulation_end)
		{
			pthread_mutex_unlock(&global->end_lock);
			break;
		}
		pthread_mutex_unlock(&global->end_lock);
		while (i < data->total_philos)
		{
			pthread_mutex_lock(&global->table->philos[i].meal_lock);
			lst_meal = get_time() - global->table->philos[i].last_meal_time;
			pthread_mutex_unlock(&global->table->philos[i].meal_lock);
			if (lst_meal >= data->ttd)
			{
				pthread_mutex_lock(&global->end_lock);
				global->simulation_end = 1;
				pthread_mutex_unlock(&global->end_lock);
				log_manager(&global->table->philos[i], "died");
				pthread_mutex_unlock(&global->table->meal_lock);
				return;
			}
			pthread_mutex_unlock(&global->table->meal_lock);
			i++;
		}
		usleep(1000);
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
void	log_manager(t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->global->table->write_lock);
	if (!philo->global->simulation_end)
		printf("%lu %d %s\n", philo->data->start_time, philo->id, message);
	pthread_mutex_unlock(&philo->global->table->write_lock);
}

bool	adm_check_dinner_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->global->simulation_end_lock);
	if (philo->global->all_meals_reached == 1)
	{
		pthread_mutex_unlock(&philo->global->simulation_end_lock);
		return (false) ;
	}
	pthread_mutex_unlock(&philo->global->simulation_end_lock);
	return (true);
}

void	adm_meal_count(t_philo *philo)
{
	pthread_mutex_lock(&philo->global->table->meal_lock);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->global->table->meal_lock);
}

