/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 20:09:25 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/01 20:13:43 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdbool.h>

//[INPUT_PARSING_MANAGER.C]
int		verify_arguments(int ac, char **av);
int		verify_arguments_2(char **av);

//[INPUT_PARSING_UTILS_1.C]
bool	array_content(char **array);
bool	is_digit(char *str);
int		ft_atoi(const char *nptr);
long	ft_atol(const char *s);

//![INPUT_PARSING_UTILS_2.C]
int		ft_isspace(int c);
int		ft_isdigit(int c);
bool	verify_number_size(char **array);
bool	number_of_philosophers(char **array);
bool	check_minimum_time(char **array);

#endif