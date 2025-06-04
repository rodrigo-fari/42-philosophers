/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing_manager.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 18:56:15 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/04 12:46:58 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PH1.h"

t_error	verify_arguments(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (INVALID_ARG_COUNT);
	else if (!array_content(av))
		return (NON_NUMERIC_ARG);
	else if (!verify_number_size(av))
		return (NUMBER_TOO_BIG);
	else if (!check_minimum_time(av))
		return (TIME_TOO_SMALL);
	else if (!number_of_dishes(av))
		return (INSUFFICIENT_DISHES);
	else if (!number_of_philosophers_2(av))
		return (TOO_FEW_PHILOSOPHERS);
	return (SUCCESS);
}

void	error_handler(t_error error)
{
	const char	*messages[] = {
	[SUCCESS] = "",
	[INVALID_ARG_COUNT] = BRED"\n[ERROR]"BWHITE"Invalid number of \
arguments.\n\n"RESET,
	[NON_NUMERIC_ARG] = BRED"\n[ERROR]"BWHITE"Numeric argument \
required.\n\n"RESET,
	[NUMBER_TOO_BIG] = BRED"\n[ERROR]"BWHITE"Input number is too \
big.\n\n"RESET,
	[TIME_TOO_SMALL] = BRED"\n[ERROR]"BWHITE"Time cannot be less than \
60ms.\n\n"RESET,
	[INSUFFICIENT_DISHES] = BRED"\n[ERROR]"BWHITE"Insuficient number of \
dishes.\n\n"RESET,
	[TOO_FEW_PHILOSOPHERS] = BRED"\n[ERROR]"BWHITE"Nunumber of \
Philosophers cannot be less then 1.\n\n"RESET,
	[MEMORY_ERROR] = BRED"\n[ERROR]"BWHITE"Unable to allocate memory.\n\n"RESET
	};

	if (error != SUCCESS)
		printf("%s", messages[error]);
}
