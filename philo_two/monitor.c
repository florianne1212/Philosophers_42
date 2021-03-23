/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 10:13:10 by fcoudert          #+#    #+#             */
/*   Updated: 2021/03/22 12:16:31 by fcoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void			write_monitor(t_info *info, int i)
{
	char	*time;
	char	*str;

	sem_wait(g_print);
	time = ft_itoa(get_micro());
	str = ft_strjoin(time, " ", info[i].index_c, " died\n");
	write(1, str, ft_strlen(str));
	free(str);
	free(time);
	g_died_check = 1;
	sem_post(g_print);
}

void			write_full(int j, int i)
{
	if (j == i)
	{
		sem_wait(g_print);
		g_died_check = 1;
		ft_putstr("full\n");
		sem_post(g_print);
	}
}

int				monitoring(t_philo philo, t_info *info)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < philo.nb_philosopher)
	{
		if ((get_milli() - info[i].last_meal_milli) >= info->philo->time_to_die)
			return (i);
		if (info->philo->monitor_meals)
		{
			if (info[i].check_eat)
				j++;
			write_full(j, (philo.nb_philosopher - 1));
			if (j == (philo.nb_philosopher - 1))
				break ;
		}
		if (i == (philo.nb_philosopher - 1))
		{
			i = 0;
			j = 0;
		}
		i++;
	}
	return (-1);
}
