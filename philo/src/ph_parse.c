/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:00:06 by rde-fari          #+#    #+#             */
/*   Updated: 2024/11/28 20:59:52 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ph_parse(char **av)
{
	verify_syntax(av);
	verify_input(av);
	ph_init_struct(av);
}

void	verify_syntax(char **av)
{
	int		i;
	int		j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if(ft_isalpha(av[i][j]))
				printerror("Alpha input forbiden.");
			j++;
		}
		i++;
	}
}

void	verify_input(char **av)
{
	int	i;
	
	if (ft_atol(av[1]) < 1)
		printerror("Too few philosophers.");
	if (ft_atol(av[1]) > 200)
		printerror("Too much philosophers.");
	i = 2;
	while (av[i] && i <= 4)
	{
		if (ft_atol(av[i]) > MAX_INT || ft_atol(av[i]) < MIN_INT)
			printerror("One of the arguments is invalid.");
		i++;
	}
}

//ac = 2 | av[1] - number_of_philosophers 
//ac = 3 | av[2] - time_to_die in milliseconds
//ac = 4 | av[3] - time_to_eat in milliseconds
//ac = 5 | av[4] - time_to_sleep in milliseconds
//ac = 6 | av[5] - [number_of_times_each_philosopher_must_eat]