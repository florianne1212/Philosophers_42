/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 10:13:10 by fcoudert          #+#    #+#             */
/*   Updated: 2021/03/18 14:50:53 by fcoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void		clean_exit(t_info *info, t_philo philo)
{
	int i;

	i = 0;
	while (i < philo.nb_philosopher)
	{
		sem_post(info->philo->forks);
		i++;
	}
	i = 0;
	while (i < philo.nb_philosopher)
	{
		pthread_join(philo.philosophers[i], NULL);
		free(info[i].index_c);
		i++;
	}
	free(info);
	sem_close(philo.display);
	sem_close(philo.forks);
	sem_close(g_print);
	sem_unlink("forks");
	sem_unlink("display");
	sem_unlink("print");
	free(philo.philosophers);
}

sem_t			*g_print = NULL;

int			main(int argc, char **argv)
{
	t_philo	philo;

	g_print = sem_creation("print", 1);
	g_died_check = 0;
	if (check_and_init(argc, argv, &philo) == 1)
		return (1);
	init_and_start(philo);
	return (0);
}
