/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 10:13:10 by fcoudert          #+#    #+#             */
/*   Updated: 2021/03/15 08:28:17 by fcoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void		clean_exit(t_info *info, t_philo philo)
{
	int		i;

	i = 0;
	while (i < philo.nb_philosopher)
	{
		sem_post(info->philo->forks);
		i++;
	}
	i = 0;
	while (i < philo.nb_philosopher)
	{
		free(info[i].index_c);
		i++;
	}
	free(info);
	sem_close(philo.forks);
	sem_close(g_print);
	sem_unlink("forks");
	sem_unlink("print");
}

sem_t		*g_print = NULL;

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
