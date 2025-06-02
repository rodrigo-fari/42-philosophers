/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_initc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:36:07 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/02 19:06:55 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//Function reponsable for controling the struct initialization
void	init_structs(char **av)
{
	t_data		*data;
	t_table		*table;
	t_philo		*philo;
	t_global	*global;

	data = NULL;
	table = NULL;
	philo = NULL;
	global = NULL;
	init_data_struct(data, av);
	init_table_struct(table, data);
	init_philo_struct(global, table, data, philo);
	init_global_struct(global, table);
}

//Function responsable for the initialization of the data struct.
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

//Function reponsable for the initialization of the table struct.
void	init_table_struct(t_table *table, char **av)
{
	int	i;

	table->forks = ft_calloc(sizeof(pthread_mutex_t),
	table->data->total_philos);
	if (!table->forks)
	{
		error_handler(MEMORY_ERROR);
		return (NULL);
	}
	i = 0;
	while (i < table->data->total_philos)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&table->meal_lock, NULL);
	pthread_mutex_init(&table->write_lock, NULL);
}

//Function reponsable for the initialization of the philosophers struct.
void	init_philo_struct(t_global *global, t_table *table, t_data *data,
				t_philo *philos)
{
	int	i;

	i = 0;
	while (i < table->data->total_philos)
	{
		philos[i].id = i + 1;
		philos[i].left_fork = &table->forks[i];
		philos[i].right_fork = &table->forks[(i + 1)
			% data->total_philos];
		philos[i].data = data;
		philos[i].global = global;
		philos[i].meals_eaten = 0;
		philos[i].last_meal_time = current_time();
		i++;
	}
}

//Function reponsable for the initialization of the global struct.
void	init_global_struct(t_global *global, t_table *table)
{
	pthread_mutex_init(&global->end_lock, NULL);
	global->simulation_end = 0;
	global->all_meals_reached = 0;
	global->table = table;
}
