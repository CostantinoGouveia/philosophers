#include "philosop.h"

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
		if (!ft_isdigit(*str))
			ft_error();
		i = i * 10 + (*str - 48);
		str++;
	}
	if ((mod * i) > 2147483647 || (mod * i) < -2147483648)
		ft_error();
	return (mod * i);
}

t_philo	*ft_sub_process(char **argv)
{
	t_philo	*a;
	char	**tmp;
	int		i;
	int		j;

	a = NULL;
	i = 0;
	tmp = ft_split(argv[1], 32);
	while (tmp[i])
	{
		j = ft_atoi_limit(tmp[i]);
		printf("%d\n", j);
		i++;
	}
	//ft_freestr(tmp);
	//free(tmp);
	return (a);
}

t_philo	*ft_process(int argc, char **argv)
{
	t_philo	*a;
	int		i;
	int		j;

	i = 1;
	a = NULL;
	if (argc > 1 && argc < 7)
	{
		if (argc == 2)
			a = ft_sub_process(argv);
		else
		{
			while (i < argc)
			{
				j = ft_atoi_limit(argv[i]);
				printf("%d\n", j);
				i++;
			}
		}
	}
	else
		ft_error();
	return (a);
}
