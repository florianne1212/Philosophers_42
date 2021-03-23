/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 10:13:10 by fcoudert          #+#    #+#             */
/*   Updated: 2021/03/22 09:47:58 by fcoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		clean_exit(t_info *info, t_philo philo)
{
	int		i;

	i = 0;
	while (i < philo.nb_philosopher)
	{
		pthread_mutex_unlock(&info->own_fork.lock_forks);
		i++;
	}
	i = 0;
	while (i < philo.nb_philosopher)
	{
		pthread_join(philo.philosophers[i], NULL);
		pthread_mutex_destroy(&info[i].own_fork.lock_forks);
		free(info[i].index_c);
		i++;
	}
	pthread_mutex_destroy(&philo.lock);
	pthread_mutex_destroy(&philo.display);
	free(philo.philosophers);
	free(info);
}

int			main(int argc, char **argv)
{
	t_philo	philo;

	g_died_check = 0;
	if (check_and_init(argc, argv, &philo) == 1)
		return (1);
	init_and_start(philo);
	return (0);
}
