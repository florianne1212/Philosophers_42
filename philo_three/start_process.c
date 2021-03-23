/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 10:13:10 by fcoudert          #+#    #+#             */
/*   Updated: 2021/03/15 08:35:56 by fcoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int			check(t_info *info)
{
	int		i;

	i = 0;
	if (pthread_create(&info->monitor, NULL, &monitor_death, info) != 0)
		return (1);
	pthread_detach(info->monitor);
	while (g_died_check == 0 && (!info->philo->monitor_meals ||
	i <= info->philo->nb_must_eat))
	{
		eat(info);
		write_stuff(info, " is sleeping\n");
		sleep_time(info->philo->time_to_sleep);
		write_stuff(info, " is thinking\n");
		i++;
	}
	exit(34);
}

int			create_process(t_philo philo, t_info *info)
{
	long	start;
	int		i;

	i = 0;
	start = get_milli();
	while (i < (philo.nb_philosopher))
	{
		info[i].pid = fork();
		info[i].start = start;
		info[i].last_meals = start;
		if (info[i].pid == 0)
		{
			check(&info[i]);
		}
		i++;
	}
	return (1);
}

int			init_and_start(t_philo philo)
{
	int		i;
	t_info	*info;

	if (!(info = malloc(sizeof(t_info) * philo.nb_philosopher)))
		return (0);
	i = 0;
	while (i < (philo.nb_philosopher))
	{
		info[i].index = i;
		info[i].index_c = ft_itoa(i + 1);
		info[i].philo = &philo;
		i++;
	}
	create_process(philo, info);
	monitor_pid(info);
	clean_exit(info, philo);
	return (0);
}
