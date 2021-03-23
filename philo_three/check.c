/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 21:41:21 by fcoudert          #+#    #+#             */
/*   Updated: 2021/02/28 19:03:24 by fcoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int		check_arg(int argc)
{
	if (argc < 5)
	{
		ft_putstr("missing arguments you need to have a least 3 arguments");
		return (1);
	}
	if (argc > 6)
	{
		ft_putstr("too much arguments you can have 4 arguments max");
		return (1);
	}
	return (0);
}

int		check_again(t_philo *philo)
{
	if (philo->monitor_meals == 1 && philo->nb_must_eat < 1)
	{
		ft_putstr("number of meal must be a least 1\n");
		return (1);
	}
	if (philo->nb_philosopher <= 1)
	{
		ft_putstr("number of philosopher must be a least 2\n");
		return (1);
	}
	return (0);
}
