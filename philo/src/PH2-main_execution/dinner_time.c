/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 02:15:19 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/05 15:33:09 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PH2.h"

void	*dinner_time(void	*arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(100);
	if (philo->data->nop == 1)
		return (single_philosohper(philo), arg);
	if (philo->data->nod == 0)
		return (arg);
	while (!check_if_dead(philo))
	{
		phiaction_think(philo);
		if (phiaction_eat(philo) == -1)
			break ;
		pthread_mutex_lock(philo->meal_lock);
		if (philo->meal_count == philo->data->nod)
			return (pthread_mutex_unlock(philo->meal_lock), arg);
		pthread_mutex_unlock(philo->meal_lock);
		if (phiaction_sleep(philo) == -1)
			break ;
		usleep(50);
	}
	return (arg);
}

void	phiaction_think(t_philo *philo)
{
	log_msg(philo, THINKING);
}

int	phiaction_eat(t_philo *philo)
{
	if (check_if_dead(philo) == true)
		return (-1);
	phiaction_forkon(philo);
	if (check_if_dead(philo) == true || philosopher_status(philo) == DEAD)
		return (phiaction_forkoff(philo), -1);
	log_msg(philo, EATING);
	pthread_mutex_lock(philo->last_meal_lock);
	philo->last_meal = get_time();
	pthread_mutex_unlock(philo->last_meal_lock);
	while (get_time() - philo->last_meal < (size_t)philo->data->tte)
	{
		if (philosopher_status(philo) == DEAD)
			return (phiaction_forkoff(philo), -1);
		usleep(50);
	}
	pthread_mutex_lock(philo->meal_lock);
	philo->meal_count++;
	pthread_mutex_unlock(philo->meal_lock);
	phiaction_forkoff(philo);
	if (philosopher_status(philo) == DEAD)
		return (-1);
	return (0);
}

int	phiaction_sleep(t_philo *philo)
{
	pthread_mutex_lock(philo->table->dead_philo_lock);
	if (philo->table->dead_philo == true)
		return (pthread_mutex_unlock(philo->table->dead_philo_lock), -1);
	pthread_mutex_unlock(philo->table->dead_philo_lock);
	log_msg(philo, SLEEPING);
	ft_usleep(philo->data->tts);
	return (0);
}

void	single_philosohper(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	log_msg(philo, FORK_TAKEN);
	pthread_mutex_unlock(philo->l_fork);
	ft_usleep(philo->data->ttd);
	printf("%zi %d ", get_time() - philo->table->start_time, philo->id);
	printf("died\n");
	return ;
}
