/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 20:09:25 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/02 21:15:12 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdbool.h>

//[PARSING ERROR HANDLING]
# define PARSE_ERROR 0
# define PARSE_SUCCESS 1

//[INPUT_PARSING_MANAGER.C]
t_error	verify_arguments(int ac, char **av);
void	error_handler(t_error err);

//![INPUT_PARSING_UTILS_1.C]
bool	array_content(char **array);
bool	is_digit(char *str);
int		ft_atoi(const char *nptr);
long	ft_atol(const char *s);
bool	number_of_dishes(char **array);

//![INPUT_PARSING_UTILS_2.C]
int		ft_isspace(int c);
int		ft_isdigit(int c);
bool	verify_number_size(char **array);
bool	number_of_philosophers(char **array);
bool	number_of_philosophers_2(char **array);

//[INPUT_PARSING_UTILS_3.C]
int		array_len(char **array);
bool	check_minimum_time(char **array);
void	*ft_calloc(size_t nmemb, size_t size);

#endif