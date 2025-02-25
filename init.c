/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouveia <cgouveia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:51:38 by cgouveia          #+#    #+#             */
/*   Updated: 2025/02/25 14:12:05 by cgouveia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosop.h"

void	init_args(t_philo *philo, char **argv)
{
	philo->num_of_philos = ft_atoi_limit(argv[1]);
	philo->time_to_die = ft_atoi_limit(argv[2]);
	philo->time_to_eat = ft_atoi_limit(argv[3]);
	philo->time_to_sleep = ft_atoi_limit(argv[4]);
	if (argv[5])
		philo->num_times_to_eat = ft_atoi_limit(argv[5]);
	else
		philo->num_times_to_eat = -1;
}

void	init_program(t_philo *philos)
{
	program()->dead_flag = 0;
	program()->philos = philos;
	pthread_mutex_init(&program()->write_lock, NULL);
	pthread_mutex_init(&program()->dead_lock, NULL);
	pthread_mutex_init(&program()->meal_lock, NULL);
}

void	init_forks(pthread_mutex_t *forks, int num_philo)
{
	int	i;

	i = 0;
	while (i < num_philo)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	init_philos(t_philo *philos, pthread_mutex_t *forks, char **argv)
{
	int	i;

	i = 0;
	while (i < ft_atoi_limit(argv[1]))
	{
		philos[i].id = i + 1;
		philos[i].eating = 0;
		philos[i].meals_eaten = 0;
		init_args(&philos[i], argv);
		philos[i].start_time = get_current_time();
		philos[i].last_meal = get_current_time();
		philos[i].write_lock = &program()->write_lock;
		philos[i].dead_lock = &program()->dead_lock;
		philos[i].meal_lock = &program()->meal_lock;
		philos[i].dead = &program()->dead_flag;
		philos[i].l_fork = &forks[i];
		if (i == 0)
			philos[i].r_fork = &forks[philos[i].num_of_philos - 1];
		else
			philos[i].r_fork = &forks[i - 1];
		i++;
	}
}
