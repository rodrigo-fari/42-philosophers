/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:54:04 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/05 14:22:30 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PH2.h"

// printf("[DEBUG]\n");

int	main(int ac, char **av)
{
	t_error		error_code;
	t_global	*global;

	error_code = verify_arguments(ac, av);
	if (error_code != SUCCESS)
	{
		error_handler(error_code);
		return (EXIT_FAILURE);
	}
	global = malloc(sizeof(t_global));
	start_structs(&global, ac, av);
	start_simulation(global->table);
	free_program(global);
	return (EXIT_SUCCESS);
}
