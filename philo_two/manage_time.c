/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 10:13:10 by fcoudert          #+#    #+#             */
/*   Updated: 2021/03/09 19:25:09 by fcoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

long				get_milli(void)
{
	struct timeval	milli;

	gettimeofday(&milli, NULL);
	return ((milli.tv_sec) * 1000 + (milli.tv_usec) / 1000);
}

size_t				get_micro(void)
{
	long			milli;
	static long		start = -1;
	long			local_start;
	struct timeval	time;

	gettimeofday(&time, NULL);
	milli = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	if (start == -1)
		start = milli;
	local_start = start;
	return (milli - local_start);
}

size_t				sleep_time(long time)
{
	size_t			end;

	end = get_micro() + time;
	while (end > get_micro())
	{
		usleep(500);
	}
	return (1);
}
