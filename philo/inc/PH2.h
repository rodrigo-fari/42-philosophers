/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PH2.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:42:33 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/04 12:49:50 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "colors.h"

typedef struct s_global
{
	int				simulation_end;
	int				all_meals_reached;
	int				ready_threads;
	pthread_mutex_t	simulation_end_lock;
	pthread_mutex_t	all_meals_lock;
	pthread_mutex_t	end_lock;
	t_table			*table;
}	t_global;

typedef struct s_data
{
	int				total_philos;
	int				ttd;
	int				tte;
	int				tts;
	int				max_meals;
	long			start_time;
}	t_data;

typedef struct s_table
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	meal_lock;
	t_philo			*philos;
	t_data			*data;
}	t_table;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long			start_time;
	long			last_meal_time;
	pthread_t		thread_id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	meal_lock;
	t_data			*data;
	t_global		*global;
}	t_philo;


void	init_program(t_global *global, t_philo *philo, t_data *data, char **av);
void	init_data_struct(t_data	*data, char **av);
void	init_table_struct(t_table *table, t_data *data);
void	init_philo_struct(t_global *global, t_table *table, t_data *data,
			t_philo *philos);
void	init_global_struct(t_global *global, t_table *table);
void	create_join_threads(t_global *global, t_philo *philos,
			pthread_t *monitor, t_data *data);
void	create_threads(t_global *global, t_philo *philos,
			pthread_t *monitor, t_data *data);
void	join_threads(t_philo *philos, t_data *data, pthread_t *monitor);
void	*adm_monitor(void *adm_thread);
void	*ph_dinner_time(void *philo_struct);
bool	adm_check_dinner_time(t_philo *philo);
void	adm_meal_count(t_philo *philo);
void	adm_is_everyone_ok(t_global *global, t_data *data);
void	adm_is_everyone_full(t_global *global, t_data *data);
void	log_manager(t_philo *philo, char *message);
long	get_time(void);
long	current_time(long time);
long	get_time2(void);
void	ft_usleep(long int miliseconds);
void	ph_action_think(t_philo *philo);
void	ph_action_take_forks(t_philo *philo);
void	ph_action_eat(t_philo *philo);
void	ph_action_putdown_forks(t_philo *philo);
void	ph_action_sleep(t_philo *philo);

#endif