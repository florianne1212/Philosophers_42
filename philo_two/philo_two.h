/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 10:13:10 by fcoudert          #+#    #+#             */
/*   Updated: 2021/03/18 14:48:23 by fcoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include <unistd.h>
# include <sys/time.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <fcntl.h>
# include <semaphore.h>

int					g_died_check;
sem_t				*g_print;

typedef struct		s_philo
{
	pthread_t		*philosophers;
	sem_t			*forks;
	sem_t			*display;
	int				nb_philosopher;
	long			time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_must_eat;
	int				last_meal;
	int				monitor_meals;
	int				check;
}					t_philo;

typedef struct		s_info
{
	int				count_eat;
	int				index;
	char			*index_c;
	int				check_eat;
	t_philo			*philo;
	long			last_meal_milli;
}					t_info;

int					check_and_init(int argc, char **argv, t_philo *philo);
int					ft_atoi(const char *str);
void				ft_putchar(char c);
void				ft_putstr(char *str);
size_t				get_micro();
size_t				sleep_time(long time);
char				*ft_strjoin(char const *s1, char const *s2,
					char const *s3, char const *s4);
char				*ft_itoa(int n);
int					ft_strlen(char *str);
void				eat_sleep_think(t_info *info);
void				*check(void *sent);
void				write_stuff(t_info *info, char *message);
sem_t				*sem_creation(char *name, int nb);
int					init_and_start(t_philo philo);
int					check_again(t_philo *philo);
int					check_arg(int argc);
void				*check_nb_meals(void *sent);
void				*monitor_death(void *sent);
void				clean_exit(t_info *info, t_philo philo);
long				get_milli();
int					monitoring(t_philo philo, t_info *info);
void				write_monitor(t_info *info, int i);

#endif
