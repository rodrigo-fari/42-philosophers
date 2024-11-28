/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:19:21 by rde-fari          #+#    #+#             */
/*   Updated: 2024/11/28 20:59:43 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//=====================================| Colors |
# define RED "\033[31m"
# define GREEN "\033[32m"
# define ORANGE "\033[38;5;208m"
# define PURPLE "\e[35m"
# define YELLOW "\033[33m"
# define CYAN "\033[36m"
# define RESET "\033[0m"

//=====================================| Libraries |
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

//=====================================| Helper |
# define MAX_INT 2147483647
# define MIN_INT -2147483648

//=====================================| Structs |
typedef struct s_table
{
	int			max_meals;
}				t_table;

typedef struct s_philo
{
	int			**philo_id;
	int			last_meal;
	long		time_to_eat;
	long		time_to_think;
	long		time_to_die;
	t_table		*table;
}				t_philo;

//=====================================| philosophers.c |


//=====================================| ph_error.c |
void		printerror(char *str);

//=====================================| ph_parse.c |
void		ph_parse(char **av);
void		verify_syntax(char **av);
void		verify_input(char **av);

//=====================================| ph_time.c |
long		get_time(void);
long int	get_time2(void);
long		current_time(long time);
void		ft_usleep(long int miliseconds);

//=====================================| ph_utils1.c |

//=====================================| ph_init.c |
void		ph_init_struct(char **av);


#endif