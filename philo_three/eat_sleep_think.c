/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 10:13:10 by fcoudert          #+#    #+#             */
/*   Updated: 2021/03/15 08:36:26 by fcoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void		write_stuff(t_info *info, char *message)
{
	char	*str;
	char	*time;
	long	last;

	sem_wait(g_print);
	if (g_died_check == 0)
	{
		last = get_milli();
		time = ft_itoa(last - info->start);
		str = ft_strjoin(time, " ", info->index_c, message);
		write(1, str, ft_strlen(str));
		free(str);
		free(time);
	}
	sem_post(g_print);
}

void		eat(t_info *info)
{
	sem_wait(info->philo->forks);
	sem_wait(info->philo->forks);
	write_stuff(info, " has taken fork\n");
	write_stuff(info, " has taken fork\n");
	write_stuff(info, " is eating\n");
	info->last_meals = get_milli();
	sleep_time(info->philo->time_to_eat);
	sem_post(info->philo->forks);
	sem_post(info->philo->forks);
}
