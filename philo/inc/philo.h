/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:19:21 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/02 19:06:27 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//[INCLUDES]
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

//[OWN INCLUDES]
# include "colors.h"
# include "error.h"
# include "parsing.h"
# include "utils.h"

//[FOREWARD STRUCT DECLARATION]
typedef struct s_global	t_global;
typedef struct s_data	t_data;
typedef struct s_table	t_table;
typedef struct s_philo	t_philo;

//[STRUCTURES]
typedef struct s_global
{
	int				simulation_end;
	int				all_meals_reached;
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
	long			last_meal_time;
	pthread_t		thread_id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_data			*data;
	t_global		*global;
}	t_philo;

//![PH2][STRUCTURES INITIALIZATION]
void	init_structs(char **av);
void	init_data_struct(t_data	*data, char **av);
void	init_table_struct(t_table *table, char **av);
void	init_philo_struct(t_global *global, t_table *table, t_data *data,
				t_philo *philos);
void	init_global_struct(t_global *global, t_table *table);

//[PH2][TIME MACHINE]
long	current_time();
//[PH3 UTILS 1]
void	*ft_calloc(size_t nmemb, size_t size);

#endif