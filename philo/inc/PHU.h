/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PHU.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:51:09 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/05 03:05:06 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHU_H
# define PHU_H

# include "PH1.h"
# include "PH2.h"
# include "PH3.h"

typedef struct s_global	t_global;
typedef struct s_data	t_data;
typedef struct s_table	t_table;
typedef struct s_philo	t_philo;

bool	array_content(char **array);
bool	is_digit(char *str);
int		ft_atoi(const char *nptr);
long	ft_atol(const char *s);
bool	number_of_dishes(char **array);
int		ft_isspace(int c);
int		ft_isdigit(int c);
bool	verify_number_size(char **array);
bool	number_of_philosophers(char **array);
bool	number_of_philosophers_2(char **array);
int		array_len(char **array);
bool	check_minimum_time(char **array);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_usleep(size_t milliseconds);
size_t	get_time(void);
void	log_msg(t_philo *philo, int state);
bool	check_if_dead(t_philo *philo);
int		philosopher_status(t_philo *philo);
void	phiaction_kill(t_philo *philo);

#endif