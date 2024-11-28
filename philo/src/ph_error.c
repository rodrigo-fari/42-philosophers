/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:57:28 by rde-fari          #+#    #+#             */
/*   Updated: 2024/11/28 16:59:33 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	printerror(char *str)
{
	ft_printf(RED"[Error] "RESET);
	ft_printf("%s", str);
	ft_printf("\n");
	exit (1);
}

// void	frees()
// {
	
// }