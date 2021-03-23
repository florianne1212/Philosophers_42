/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 10:13:10 by fcoudert          #+#    #+#             */
/*   Updated: 2021/03/22 09:41:24 by fcoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

long				get_milli(void)
{
	struct timeval	milli;

	gettimeofday(&milli, NULL);
	return ((milli.tv_sec) * 1000 + (milli.tv_usec) / 1000);
}

size_t				get_micro(t_info *info)
{
	long			local_start;

	local_start = info->philo->start;
	return (get_milli() - local_start);
}

size_t				sleep_time(long time, t_info *info)
{
	size_t			end;

	end = get_micro(info) + time;
	while (end > get_micro(info))
	{
		usleep(500);
	}
	return (1);
}
