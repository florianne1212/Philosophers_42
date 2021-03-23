/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 18:28:13 by fcoudert          #+#    #+#             */
/*   Updated: 2021/03/20 20:08:11 by fcoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <unistd.h>
# include <sys/time.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>

int g_died_check;

typedef struct		s_philo
{
	pthread_mutex_t	lock;
	pthread_mutex_t	display;
	pthread_t		*philosophers;
	int				nb_philosopher;
	long			time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_must_eat;
	int				last_meal;
	int				monitor_meals;
	int				check;
	int				start;
}					t_philo;

typedef struct		s_fork
{
	pthread_mutex_t	lock_forks;
}					t_fork;

typedef struct		s_info
{
	int				count_eat;
	int				index;
	int				check_eat;
	char			*index_c;
	t_fork			own_fork;
	t_fork			*next_fork;
	t_philo			*philo;
	long			last_meal_milli;
}					t_info;

int					ft_atoi(const char *str);
void				ft_putchar(char c);
void				ft_putstr(char *str);
size_t				get_micro(t_info *info);
size_t				sleep_time(long time, t_info *info);
char				*ft_strjoin(char const *s1, char const *s2,
					char const *s3, char const *s4);
char				*ft_itoa(int n);
int					ft_strlen(char *str);
int					check_and_init(int argc, char **argv, t_philo *philo);
void				eat_sleep_think(t_info *info);
void				*check(void *sent);
void				*monitor_death(void *sent);
void				write_stuff(t_info *info, char *message);
int					check_again(t_philo *philo);
int					check_arg(int argc);
void				second_init(t_philo *phil, t_info *info);
int					init_and_start(t_philo philo);
void				*check_nb_meals(void *sent);
void				clean_exit(t_info *info, t_philo philo);
long				get_milli(void);
int					monitoring(t_philo philo, t_info *info);
void				write_monitor(t_info *info, int i);

#endif
