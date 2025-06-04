/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PH2.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:42:33 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/04 23:44:51 by rde-fari         ###   ########.fr       */
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
	t_data			*data;//Program general info.
	t_table			*table;//Table general info.
}	t_global;

typedef struct s_data
{
	int				nop;//Number of philosophers.
	int				ttd;//Time to die.
	int				tte;//Time to eat.
	int				tts;//Time to sleep.
	int				nod;//Number of dishes.
}	t_data;

typedef struct s_table
{
	long			start_time;//Save the dinner starting time.
	bool			dead_philo;//Set philo dead.
	t_philo			*philos;//Philosophers general info.
	pthread_t		monitor_thread;//Check philosopher's integrity.
	pthread_mutex_t	*msg_lock;//Lock -> Log message.
	pthread_mutex_t	*fork_lock;//Lock -> Forks.
	pthread_mutex_t	*dead_philo_lock;//Lock -> dead_philo flag.
}	t_table;

typedef struct s_philo
{
	int				id;//Philosopher id.
	long			last_meal;//Time since last meal.
	t_data			*data;//Data general info.
	t_table			*table;//Table general info.
	pthread_t		thread_id;//Philosopher DNA ;p
	pthread_mutex_t	*l_fork;//Lock -> Left fork.
	pthread_mutex_t	*r_fork;//Lock -> Right fork.
	pthread_mutex_t	*meal_lock;//Lock -> Meal count.
	pthread_mutex_t	*last_meal_lock;//Lock -> las_meal var.
}	t_philo;



#endif