/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PHU.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:51:09 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/04 12:51:39 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHU_H
# define PHU_H

# include "PH1.h"

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

#endif