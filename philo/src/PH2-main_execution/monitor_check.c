/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 02:15:39 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/05 02:56:43 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PH2.h"

void	*monitor_check(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	while (true)
	{
		if (check_for_dead_philo(table->philo) == -1
			|| check_if_meal_done(table->philo) == -1)
			break ;
	}
	return (arg);
}

int	check_if_meal_done(t_philo *philo)
{
	int	i;
	int	meals_eatten;

	i = 0;
	meals_eatten = 0;
	if (philo->data->nod < 0)
		return (0);
	i = 0;
	meals_eatten = 0;
	while (i < philo->data->nop)
	{
		pthread_mutex_lock(philo[i].meal_lock);
		if (philo[i].meal_count >= philo->data->nod)
			meals_eatten++;
		pthread_mutex_unlock(philo[i].meal_lock);
		i++;
	}
	if (meals_eatten == philo->data->nod)
		return (-1);
	return (0);
}

int	check_for_dead_philo(t_philo *philo)
{
	int	i;

	i = 0;
	if (philo->data->nop < 2)
		return (-1);
	while (i < philo->data->nop)
	{
		if (philosopher_status(&philo[i]) == DEAD)
			return (-1);
		i++;
	}
	return (0);
}

