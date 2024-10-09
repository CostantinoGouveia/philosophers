/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouveia <cgouveia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 08:11:28 by cgouveia          #+#    #+#             */
/*   Updated: 2024/10/09 09:03:20 by cgouveia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosop.h"

int main (int ac, char *av[])
{
	t_philo    *philos;

    philos = ft_process(ac, av);
	if (!philos)
	{
		ft_error();
	}
}
