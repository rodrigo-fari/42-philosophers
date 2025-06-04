/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PH1.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:19:21 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/04 12:51:01 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PH1_H
# define PH1_H

# include "PH2.h"

# define PARSE_ERROR 0
# define PARSE_SUCCESS 1

typedef enum e_error
{
	SUCCESS = 0,
	INVALID_ARG_COUNT,
	NON_NUMERIC_ARG,
	NUMBER_TOO_BIG,
	TIME_TOO_SMALL,
	INSUFFICIENT_DISHES,
	TOO_FEW_PHILOSOPHERS,
	MEMORY_ERROR
}	t_error;

t_error	verify_arguments(int ac, char **av);
void	error_handler(t_error err);

#endif