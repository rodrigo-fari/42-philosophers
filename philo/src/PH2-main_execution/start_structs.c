/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 00:02:36 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/05 00:47:10 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PH2.h"

void	start_structs(t_global **global, int ac, char **av)
{
	(*global)->data = init_data_struct(ac, av);
	(*global)->table = init_table_struct((*global)->data);
}

t_data	*init_data_struct(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(data));
	data->nop = ft_atoi(av[1]);
	data->ttd = ft_atoi(av[2]);
	data->tte = ft_atoi(av[3]);
	data->tts = ft_atoi(av[4]);
	if (ac == 6)
		data->nod = ft_atoi(av[5]);
	else
		data->nod = -1;
	return (data);
}

t_table	*init_table_struct(t_data *data)
{
	t_table			*table;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	int				i;

	table = malloc(sizeof(t_table));
	philo = malloc(sizeof(t_philo));
	forks = malloc(sizeof(pthread_mutex_t) * data->nop);
	table->msg_lock = malloc(sizeof(pthread_mutex_t));
	table->dead_philo_lock = malloc(sizeof(pthread_mutex_t));
	table->data = data;
	forks = create_forks(&forks, data);
	table->forks = forks;
	philo = create_philo(&philo, table, forks);
	table->philos = philo;
	table->dead_philo = false;
	pthread_mutex_init(table->dead_philo_lock, NULL);
	pthread_mutex_init(table->msg_lock, NULL);
	return (table);
}
