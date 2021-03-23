/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 10:13:10 by fcoudert          #+#    #+#             */
/*   Updated: 2021/02/27 16:01:42 by fcoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void		init(int argc, char **argv, t_philo *philo)
{
	philo->nb_philosopher = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	philo->forks = sem_creation("forks", philo->nb_philosopher);
	philo->display = sem_creation("display", 1);
	if (argc > 5)
	{
		philo->monitor_meals = 1;
		philo->nb_must_eat = ft_atoi(argv[5]);
	}
	else
		philo->monitor_meals = 0;
}

int			init_philo(t_philo *philo)
{
	if (!(philo->philosophers = malloc(sizeof(pthread_t)
	* philo->nb_philosopher)))
		return (1);
	return (0);
}

int			check_and_init(int argc, char **argv, t_philo *philo)
{
	if (check_arg(argc) == 1)
		return (1);
	init(argc, argv, philo);
	if (check_again(philo))
		return (1);
	if (init_philo(philo) == 1)
		return (1);
	return (0);
}
