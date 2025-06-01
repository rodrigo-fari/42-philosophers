/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error_manager.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 18:56:15 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/01 20:03:52 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	verify_arguments(int ac, char **av)
{
	if (ac < 5 || ac > 6)
	{
		printf(BRED"\n[ERROR]"BWHITE"Invalid number of arguments.\n\n"RESET);
		return (ERROR);
	}
	else if (!array_content(av))
	{
		printf(BRED"\n[ERROR]"BWHITE"Numeric argument required.\n\n"RESET);
		return (ERROR);
	}
	else if (!verify_number_size(av))
	{
		printf(BRED"\n[ERROR]"BWHITE"Input number is too big.\n\n"RESET);
		return (ERROR);
	}
	return (verify_arguments_2(av));
}

int	verify_arguments_2(char **av)
{
	if (!check_minimum_time(av))
	{
		printf(BRED"\n[ERROR]"BWHITE"Time cannot be less than 60ms.\n\n"RESET);
		return (ERROR);
	}
	if (!number_of_philosophers(av))
		printf(BYELLOW"\n[WARNING]"BWHITE"Number of philosophers insufficient.\
\n"BYELLOW"[WARNING]"BWHITE"Philosopher 1 will starve.\n\n"RESET);
	return (0);
}
