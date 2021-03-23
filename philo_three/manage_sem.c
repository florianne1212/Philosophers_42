/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_sem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 10:13:10 by fcoudert          #+#    #+#             */
/*   Updated: 2021/02/06 14:25:42 by fcoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

sem_t		*sem_creation(char *name, int nb)
{
	sem_t	*sem;

	sem = sem_open(name, O_CREAT | O_EXCL, S_IRWXU, nb);
	while (sem == SEM_FAILED)
	{
		sem_unlink(name);
		sem = sem_open(name, O_CREAT | O_EXCL, S_IRWXU, nb);
	}
	return (sem);
}
