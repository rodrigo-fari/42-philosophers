/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 00:22:24 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/05 14:21:46 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PH2.h"

pthread_mutex_t	*create_forks(pthread_mutex_t *forks, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nop)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	return (forks);
}

t_philo	*create_philo(t_philo *philo, t_table *table, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < table->data->nop)
	{
		philo[i].id = i + 1;
		philo[i].last_meal = 0;
		philo[i].meal_count = 0;
		philo[i].start_time = 0;
		philo[i].table = table;
		philo[i].data = table->data;
		philo[i].l_fork = &forks[i];
		philo[i].r_fork = &forks[(i + 1) % table->data->nop];
		philo[i].meal_lock = malloc(sizeof(pthread_mutex_t));
		philo[i].last_meal_lock = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(philo->meal_lock, NULL);
		pthread_mutex_init(philo->last_meal_lock, NULL);
		i++;
	}
	return (philo);
}
