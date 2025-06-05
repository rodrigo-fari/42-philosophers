/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PH1.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:19:21 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/05 14:22:49 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PH1_H
# define PH1_H

# include "PH2.h"
# include "PH3.h"
# include "PHU.h"

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

//printf("[DEBUG] Fork  [ %d ] Limpo.\n", (i + 1)); (free_program)
//printf("[DEBUG] Fork  [ %d ] Inicializado.\n", (i + 1)); (forks)
//printf("[DEBUG] Philo [ %d ] Criado.\n", philo[i].id); (philos)
//printf("[DEBUG] Programa finalizado com sucesso! \n"); (start)
//printf("[DEBUG] Parsing realizado com sucesso.\n"); (finish)

#endif