/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 10:13:10 by fcoudert          #+#    #+#             */
/*   Updated: 2021/03/22 09:15:57 by fcoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

#include <string.h>

void		write_stuff(t_info *info, char *message)
{
	char	*str;
	char	*time;

	pthread_mutex_lock(&info->philo->display);
	if (g_died_check == 0)
	{
		time = ft_itoa(get_micro(info));
		str = ft_strjoin(time, " ", info->index_c, message);
		write(1, str, ft_strlen(str));
		free(str);
		free(time);
	}
	pthread_mutex_unlock(&info->philo->display);
}

void		take_fork(t_info *info)
{
	if ((info->index % 2) == 0)
	{
		if (pthread_mutex_lock(&info->next_fork->lock_forks) != 0)
			ft_putstr("ERROR\n");
		write_stuff(info, " has taken fork\n");
	}
	if (pthread_mutex_lock(&info->own_fork.lock_forks) != 0)
		ft_putstr("ERROR\n");
	write_stuff(info, " has taken fork\n");
	if ((info->index % 2) == 1)
	{
		if (pthread_mutex_lock(&info->next_fork->lock_forks) != 0)
			ft_putstr("ERROR\n");
		write_stuff(info, " has taken fork\n");
	}
}

void		leave_fork(t_info *info)
{
	pthread_mutex_unlock(&info->own_fork.lock_forks);
	pthread_mutex_unlock(&info->next_fork->lock_forks);
}

void		eat(t_info *info)
{
	take_fork(info);
	write_stuff(info, " is eating\n");
	info->last_meal_milli = get_milli();
	sleep_time(info->philo->time_to_eat, info);
	leave_fork(info);
}

void		eat_sleep_think(t_info *info)
{
	eat(info);
	info->count_eat += 1;
	if (info->philo->monitor_meals &&
	info->count_eat > info->philo->nb_must_eat)
		info->check_eat = 1;
	write_stuff(info, " is sleeping\n");
	sleep_time(info->philo->time_to_sleep, info);
	write_stuff(info, " is thinking\n");
	if ((info->philo->nb_philosopher % 2) == 1)
		usleep(500);
}
