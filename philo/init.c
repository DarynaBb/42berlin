#include "philo.h"

// 5

static int	is_valid_number(int argc, char **argv)
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

int	parse_args(int argc, char **argv, t_data *data)
{
	if (argc != 5 && argc != 6)
	{
		printf("Usage: ./philo num_philo time_to_die time_to_eat ");
		printf("time_to_sleep [num_times_each_philo_must_eat]\n");
		return (0);
	}
	if (!is_valid_number(argc, argv))
		return (0);
	data->num_philos = ft_atol(argv[1]);
	data->time_to_die = ft_atol(argv[2]);
	data->time_to_eat = ft_atol(argv[3]);
	data->time_to_sleep = ft_atol(argv[4]);
	data->max_meals = -1;
	if (argc == 6)
		data->max_meals = ft_atol(argv[5]);
	if (data->num_philos <= 0 || data->time_to_die < 0
		|| data->time_to_eat < 0 || data->time_to_sleep < 0 || (argc == 6 && data->max_meals <= 0))
	{
		printf("Error: All arguments must be positive integers.\n");
		return (0);
	}
	return (1);
}

t_data	*init_data(t_data *data)
{
	data->someone_died = 0;
	data->start_time = get_time();
	data->forks = NULL;
	data->philos = NULL;
	if (pthread_mutex_init(&data->print_lock, NULL) != 0)
	{
		free(data);
		return (NULL);
	}
	if (pthread_mutex_init(&data->death_lock, NULL) != 0)
	{
		free(data);
		return (NULL);
	}
	if (pthread_mutex_init(&data->meal_lock, NULL) != 0)
	{
		free(data);
		return (NULL);
	}
	if (pthread_mutex_init(&data->start_lock, NULL) != 0)
	{
		free(data);
		return (NULL);
	}
	return (data);
}

int	init_forks(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
	if (!data->forks)
		return (0);
	while (i < data->num_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&data->forks[i]);
			free(data->forks);
			return (0);
		}
		i++;
	}
	return (1);
}

int	init_philos(t_data *data)
{
	int	i;

	i = 0;
	data->philos = malloc(sizeof(t_philo) * data->num_philos);
	if (!data->philos)
		return (0);
	while (i < data->num_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meals_eaten = 0;
		data->philos[i].last_meal_time = data->start_time;
		data->philos[i].data = data;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->num_philos];
		data->philos[i].has_left_fork = 0;
		data->philos[i].has_right_fork = 0;
		data->philos->left_fork_available = 1;
		data->philos->right_fork_available = 1;
		i++;
	}
	return (1);
	}
