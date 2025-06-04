/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:54:04 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/05 00:49:41 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PH2.h"

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
	printf("parsing done\n");
	global = malloc(sizeof(t_global));
	start_structs(&global, ac, av);
	start_simulation(global->table, global->table->philos);//[DEBUG] not implemented yet
	free_program();//[DEBUG] not implemented yet
	return (EXIT_SUCCESS);
}
