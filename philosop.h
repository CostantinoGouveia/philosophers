/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosop.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouveia <cgouveia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 08:15:40 by cgouveia          #+#    #+#             */
/*   Updated: 2025/02/25 14:25:53 by cgouveia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOP_H
# define PHILOSOP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				num_of_philos;
	int				num_times_to_eat;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}					t_philo;

typedef struct s_program
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philos;
}					t_program;

t_program	*program(void);
size_t		get_current_time(void);
bool		philo_dead(t_philo *philo);
void		eating(t_philo *philo);
void		thinking(t_philo *philo);
void		sleeping(t_philo *philo);
void		write_msg(char *str, t_philo *philo, int id);
void		init_forks(pthread_mutex_t *forks, int num_philo);
void		init_args(t_philo *philo, char **argv);
void		init_program(t_philo *philos);
void		init_philos(t_philo *philos, pthread_mutex_t *forks, char **argv);
void		*routine(void *arg);
void		mutexes_destroy(char *str, pthread_mutex_t *forks);
void		ft_error(void);
char		**ft_split(char const *s, char c);
char		*ft_strncpy(char *dest, const char *src, size_t n);
int			ft_usleep(size_t milliseconds);
int			ft_isdigit(int c);
int			ft_strlen(char *str);
int			ft_atoi_limit(const char *str);
int			check_arg_content(char *arg);
int			check_valid_args(char **argv);
int			create_thread(pthread_mutex_t *forks);
int			is_num_eat(t_philo *philos);

#endif
