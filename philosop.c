/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouveia <cgouveia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 08:11:28 by cgouveia          #+#    #+#             */
/*   Updated: 2025/02/25 14:24:46 by cgouveia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosop.h"

int	is_did_aux(t_philo *philo, size_t time_to_die)
{
	pthread_mutex_lock(philo->meal_lock);
	if ((get_current_time() - philo->last_meal)
		>= time_to_die && philo->eating == 0)
		return (pthread_mutex_unlock(philo->meal_lock), 1);
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

int	is_did(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo[0].num_of_philos)
	{
		if (is_did_aux(&philo[i], philo[i].time_to_die))
		{
			write_msg("died", &philo[i], philo[i].id);
			pthread_mutex_lock(philo[0].dead_lock);
			*philo->dead = 1;
			pthread_mutex_unlock(philo[0].dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

void	*observando(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (true)
		if (is_did(philo) || is_num_eat(philo))
			break ;
	return (arg);
}

int	create_thread(pthread_mutex_t *forks)
{
	pthread_t	observar;
	int			i;

	if (pthread_create(&observar, NULL, &observando, program()->philos))
		mutexes_destroy("Thread creation error", forks);
	i = 0;
	while (i < program()->philos->num_of_philos)
	{
		if (pthread_create(&program()->philos[i].thread, NULL, &routine,
				&program()->philos[i]) != 0)
			mutexes_destroy("Thread creation error", forks);
		i++;
	}
	i = 0;
	if (pthread_join(observar, NULL) != 0)
		mutexes_destroy("Thread join error", forks);
	while (i < program()->philos[0].num_of_philos)
	{
		if (pthread_join(program()->philos[i].thread, NULL) != 0)
			mutexes_destroy("Thread creation error", forks);
		i++;
	}
	return (0);
}

int	main(int ac, char *av[])
{
	pthread_mutex_t	*forks;
	t_philo			*philos;

	if (ac != 5 && ac != 6)
		return (write(2, "Numero de argumentos errado\n", 27), 1);
	if (check_valid_args(av) == 1)
		return (1);
	philos = malloc(sizeof(t_philo) * ft_atoi_limit(av[1]));
	if (!philos)
		return (1);
	forks = malloc(sizeof(pthread_mutex_t) * ft_atoi_limit(av[1]));
	if (!forks)
		return (1);
	init_program(philos);
	init_forks(forks, ft_atoi_limit(av[1]));
	init_philos(philos, forks, av);
	create_thread(forks);
	mutexes_destroy(NULL, forks);
	free(philos);
	free(forks);
	return (0);
}
