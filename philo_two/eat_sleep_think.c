/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 10:13:10 by fcoudert          #+#    #+#             */
/*   Updated: 2021/03/22 09:15:24 by fcoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void		write_stuff(t_info *info, char *message)
{
	char	*str;
	char	*time;

	sem_wait(g_print);
	if (g_died_check == 0)
	{
		time = ft_itoa(get_micro());
		str = ft_strjoin(time, " ", info->index_c, message);
		write(1, str, ft_strlen(str));
		free(str);
		free(time);
	}
	sem_post(g_print);
}

void		eat(t_info *info)
{
	sem_wait(info->philo->display);
	sem_wait(info->philo->forks);
	if (g_died_check)
	{
		sem_post(info->philo->display);
		sem_post(info->philo->forks);
		return ;
	}
	write_stuff(info, " has taken fork\n");
	sem_wait(info->philo->forks);
	if (g_died_check)
	{
		sem_post(info->philo->display);
		sem_post(info->philo->forks);
		sem_post(info->philo->forks);
		return ;
	}
	write_stuff(info, " has taken fork\n");
	write_stuff(info, " is eating\n");
	sem_post(info->philo->display);
	info->last_meal_milli = get_milli();
	sleep_time(info->philo->time_to_eat);
	sem_post(info->philo->forks);
	sem_post(info->philo->forks);
}

void		eat_sleep_think(t_info *info)
{
	eat(info);
	if (g_died_check)
		return ;
	info->count_eat += 1;
	if (info->philo->monitor_meals &&
		info->count_eat > info->philo->nb_must_eat)
		info->check_eat = 1;
	write_stuff(info, " is sleeping\n");
	sleep_time(info->philo->time_to_sleep);
	write_stuff(info, " is thinking\n");
}
