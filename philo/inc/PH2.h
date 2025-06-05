/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PH2.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 00:54:25 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/05 02:59:51 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PH2_H
# define PH2_H

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "colors.h"
# include "PH1.h"
# include "PH3.h"
# include "PHU.h"

# define DEAD 0
# define ALIVE 1
# define FORK_TAKEN 2
# define EATING 3
# define SLEEPING 4
# define THINKING 5

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
	t_data			*data;
	t_philo			*philo;//philosophers general info.
	pthread_t		monitor_thread;//Check philosopher's integrity.
	pthread_mutex_t	*msg_lock;//Lock -> Log message.
	pthread_mutex_t	*forks;//Lock -> Forks.
	pthread_mutex_t	*dead_philo_lock;//Lock -> dead_philo flag.
}	t_table;

typedef struct s_philo
{
	int				id;//philosopher id.
	int				meal_count;//Saves the meal count for each philosopher.
	long			last_meal;//Time since last meal.
	long			start_time;//Time since philosopher born.
	t_data			*data;//Data general info.
	t_table			*table;//Table general info.
	pthread_t		thread_id;//philosopher DNA ;p
	pthread_mutex_t	*l_fork;//Lock -> Left fork.
	pthread_mutex_t	*r_fork;//Lock -> Right fork.
	pthread_mutex_t	*meal_lock;//Lock -> Meal count.
	pthread_mutex_t	*last_meal_lock;//Lock -> las_meal var.
}	t_philo;

void			start_structs(t_global **global, int ac, char **av);
t_data			*init_data_struct(int ac, char **av);
t_table			*init_table_struct(t_data *data);
pthread_mutex_t	*create_forks(pthread_mutex_t *forks, t_data *data);
t_philo			*create_philo(t_philo *philo, t_table *table,
					pthread_mutex_t *forks);
void			start_simulation(t_table *table);
void			create_threads(t_table *table);
void			*monitor_check(void *arg);
void			*dinner_time(void	*arg);
void			join_threads(t_table *table);
void			single_philosohper(t_philo *philo);
int				phiaction_sleep(t_philo *philo);
int				phiaction_eat(t_philo *philo);
void			phiaction_think(t_philo *philo);
void			*dinner_time(void	*arg);
void			phiaction_forkon(t_philo *philo);
void			phiaction_forkoff(t_philo *philo);
int				check_for_dead_philo(t_philo *philo);
int				check_if_meal_done(t_philo *philo);
void			*monitor_check(void *arg);

#endif