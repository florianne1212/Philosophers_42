/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 10:13:10 by fcoudert          #+#    #+#             */
/*   Updated: 2021/03/22 12:17:06 by fcoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void		*monitor_death(void *sent)
{
	t_info	*info;
	long	milli;
	long	diff;
	char	*str;
	char	*time;

	info = (t_info *)sent;
	while (1 && g_died_check == 0)
	{
		milli = get_milli();
		diff = milli - info->last_meals;
		if (diff >= info->philo->time_to_die && g_died_check == 0)
		{
			sem_wait(g_print);
			time = ft_itoa(milli - info->start);
			str = ft_strjoin(time, " ", info->index_c, " died");
			write(1, str, ft_strlen(str));
			free(str);
			free(time);
			exit(12);
		}
		usleep(1000);
	}
	return (NULL);
}

void		kill_philo(t_info *info)
{
	int		i;

	i = 0;
	while (i < info->philo->nb_philosopher)
	{
		kill(info[i].pid, SIGKILL);
		i++;
	}
}

int			exit_status(int status, t_info *info)
{
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == 12)
		{
			kill_philo(info);
			sem_post(g_print);
			return (12);
		}
		if (WEXITSTATUS(status) == 34)
		{
			info->philo->checker++;
			if (info->philo->checker == (info->philo->nb_philosopher))
			{
				sem_wait(g_print);
				ft_putstr("full\n");
				kill_philo(info);
				sem_post(g_print);
				return (24);
			}
		}
	}
	return (0);
}

void		monitor_pid(t_info *info)
{
	int		status;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	status = 0;
	info->philo->checker = 0;
	while (i < info->philo->nb_philosopher)
	{
		waitpid(info[i].pid, &status, WNOHANG);
		ret = exit_status(status, info);
		if (ret != 0)
			break ;
		i++;
		if (i == info->philo->nb_philosopher)
		{
			info->philo->checker = 0;
			i = 0;
		}
	}
	return ;
}
