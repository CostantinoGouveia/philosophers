/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouveia <cgouveia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:08:27 by cgouveia          #+#    #+#             */
/*   Updated: 2025/02/25 14:14:22 by cgouveia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosop.h"

t_program	*program(void)
{
	static t_program	d;

	return (&d);
}

void	ft_error(void)
{	
	write (2, "Error\n", 6);
	exit(1);
}

int	ft_atoi_limit(const char *str)
{
	int				mod;
	long long int	i;

	i = 0;
	mod = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
	{
		mod = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		i = i * 10 + (*str - 48);
		str++;
	}
	if ((mod * i) > 2147483647 || (mod * i) < -2147483648)
		ft_error();
	return (mod * i);
}

int	check_arg_content(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (!ft_isdigit(arg[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_valid_args(char **argv)
{
	if (ft_atoi_limit(argv[1]) > 200 || ft_atoi_limit(argv[1]) <= 0
		|| check_arg_content(argv[1]) == 1)
		return (write(2, "numero de philosophers invalido\n", 32), 1);
	if (ft_atoi_limit(argv[2]) <= 0 || check_arg_content(argv[2]) == 1)
		return (write(2, "time to die invalido\n", 21), 1);
	if (ft_atoi_limit(argv[3]) <= 0 || check_arg_content(argv[3]) == 1)
		return (write(2, "time to eat invalido\n", 21), 1);
	if (ft_atoi_limit(argv[4]) <= 0 || check_arg_content(argv[4]) == 1)
		return (write(2, "time to sleep invalido\n", 23), 1);
	if (argv[5]
		&& (ft_atoi_limit(argv[5]) < 0 || check_arg_content(argv[5]) == 1))
		return (write(2, "numero de times que filosofos têm para comer\n",
				45), 1);
	return (0);
}
