#include "philo.h"

int	is_valid_number(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_numeric(argv[i]))
		{
			printf("Error: Argument %d ('%s') must be a positive integer.\n", i, argv[i]);
			return (0);
		}
		i++;
	}
	return (1);
}

int	parse_args(int argc, char **argv, t_args *args)
{
	if (argc != 5 && argc != 6)
	{
		printf("Usage: ./philo num_philo time_to_die time_to_eat ");
		printf("time_to_sleep [num_times_each_philo_must_eat]\n");
		return (0);
	}
	if (!is_valid_number(argc, argv))
		return (0);
	args->num_philo = ft_atol(argv[1]);
	args->time_to_die = ft_atol(argv[2]);
	args->time_to_eat = ft_atol(argv[3]);
	args->time_to_sleep = ft_atol(argv[4]);
	args->max_meals = -1;
	if (argc == 6)
		args->max_meals = ft_atol(argv[5]);
	if (args->num_philo <= 0 || args->time_to_die < 0
		|| args->time_to_eat < 0 || args->time_to_sleep < 0)
	{
		printf("Error: All arguments must be positive integers.\n");
		return (0);
	}
	return (1);
}
