/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PH2.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:42:33 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/04 22:11:45 by rde-fari         ###   ########.fr       */
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
# include "PH2.h"
# include "PH3.h"
# include "PHU.h"

typedef struct s_global	t_global;
typedef struct s_data	t_data;
typedef struct s_table	t_table;
typedef struct s_philo	t_philo;

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




#endif