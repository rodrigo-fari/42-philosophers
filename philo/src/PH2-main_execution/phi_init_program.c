/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_init_program.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:36:07 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/04 00:00:53 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_program(t_global *global, t_philo *philos, t_data *data, char **av)
{
	t_table		table;
	pthread_t	monitor;

	philos = malloc(sizeof(t_philo) * atoi(av[1]));
	if (!philos)
	{
		error_handler(MEMORY_ERROR);
		return ;
	}
	init_data_struct(data, av);
	init_table_struct(&table, data);
	init_global_struct(global, &table);
	init_philo_struct(global, &table, data, philos);
	create_join_threads(global, philos, &monitor, data);
	free_program(data, global, philos);
}

void	init_data_struct(t_data	*data, char **av)
{
	data->total_philos = ft_atoi(av[1]);
	data->ttd = ft_atoi(av[2]);
	data->tte = ft_atoi(av[3]);
	data->tts = ft_atoi(av[4]);
	if (av[5])
		data->max_meals = ft_atoi(av[5]);
	else
		data->max_meals = -1;
}

void	init_table_struct(t_table *table, t_data *data)
{
	int	i;

	table->data = data;
	table->forks = malloc(data->total_philos * sizeof(pthread_mutex_t));
	if (!table->forks)
		error_handler(MEMORY_ERROR);
	i = 0;
	while (i < data->total_philos)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
	table->philos = NULL;
	pthread_mutex_init(&table->write_lock, NULL);
}

void	init_philo_struct(t_global *global, t_table *table, t_data *data,
				t_philo *philos)
{
	int	i;

	i = 0;
	while (i < data->total_philos)
	{
		philos[i].id = i + 1;
		philos[i].left_fork = &table->forks[i];
		philos[i].right_fork = &table->forks[(i + 1)
			% data->total_philos];
		philos[i].data = data;
		philos[i].global = global;
		philos[i].meals_eaten = 0;
		philos[i].last_meal_time = get_time();
		pthread_mutex_init(&philos[i].meal_lock, NULL);
		i++;
	}
	table->philos = philos;
}

void	init_global_struct(t_global *global, t_table *table)
{
	pthread_mutex_init(&global->end_lock, NULL);
	pthread_mutex_init(&global->all_meals_lock, NULL);
	global->simulation_end = 0;
	global->all_meals_reached = 0;
	global->ready_threads = 0;
	global->table = table;
}
