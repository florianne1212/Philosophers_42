/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 10:13:10 by fcoudert          #+#    #+#             */
/*   Updated: 2021/03/18 14:50:27 by fcoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void			*check(void *sent)
{
	t_info		*info;
	int			i;

	i = 0;
	info = (t_info*)sent;
	while (g_died_check == 0)
	{
		eat_sleep_think(info);
		i++;
	}
	return (NULL);
}

void			start_thread(t_philo philo, t_info *info)
{
	int			i;
	int			error;
	long		start;
	int			ret;

	i = 0;
	start = get_milli();
	while (i < philo.nb_philosopher)
	{
		info[i].last_meal_milli = start;
		error = pthread_create(&(philo.philosophers[i]),
		NULL, &check, &info[i]);
		if (error != 0)
			ft_putstr("error while creating thread");
		i++;
	}
	ret = monitoring(philo, info);
	if (ret != -1)
		write_monitor(info, ret);
	clean_exit(info, philo);
}

int				init_and_start(t_philo philo)
{
	int			i;
	t_info		*info;

	i = 0;
	if (!(info = malloc(sizeof(t_info) * philo.nb_philosopher)))
		return (0);
	while (i < philo.nb_philosopher)
	{
		info[i].index = i;
		info[i].count_eat = 0;
		info[i].index_c = ft_itoa(i + 1);
		info[i].philo = &philo;
		info[i].check_eat = 0;
		i++;
	}
	start_thread(philo, info);
	return (1);
}
