/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 10:13:10 by fcoudert          #+#    #+#             */
/*   Updated: 2021/03/13 14:59:53 by fcoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include <unistd.h>
# include <sys/time.h>
# include <stdio.h>
# include <fcntl.h>
# include <pthread.h>
# include <stdlib.h>
# include <semaphore.h>
# include <signal.h>
# include <sys/wait.h>

int					g_died_check;
sem_t				*g_print;

typedef struct		s_philo
{
	pthread_t		philosophers;
	sem_t			*forks;
	sem_t			*time;
	long			last_meal_milli;
	int				nb_philosopher;
	long			time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_must_eat;
	int				monitor_meals;
	int				monitor_eat;
	int				checker;
}					t_philo;

typedef struct		s_info
{
	int				index;
	char			*index_c;
	int				pid;
	long			start;
	long			last_meals;
	pthread_t		monitor;
	t_philo			*philo;
}					t_info;

int					check_and_init(int argc, char **argv, t_philo *philo);
int					ft_atoi(const char *str);
void				ft_putchar(char c);
void				ft_putstr(char *str);
size_t				get_micro();
size_t				sleep_time(long time);
void				*monitor_last_meal(void *sent);
char				*ft_strjoin(char const *s1, char const *s2,
					char const *s3, char const *s4);
char				*ft_itoa(int n);
int					ft_strlen(char *str);
void				eat_sleep_think(t_info *info);
int					check(t_info *info);
void				*monitor_death(void *sent);
void				write_stuff(t_info *info, char *message);
sem_t				*sem_creation(char *name, int nb);
int					check_again(t_philo *philo);
int					check_arg(int argc);
int					create_process(t_philo philo, t_info *info);
void				monitor_pid(t_info *info);
void				clean_exit(t_info *info, t_philo philo);
void				eat(t_info *info);
long				get_milli();
int					init_and_start(t_philo philo);

#endif
