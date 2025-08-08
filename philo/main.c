#include "philo.h"
// 2
void	print_data(t_data *data)
{
	if (!data)
		return;
	printf("Number of philosophers: %d\n", data->num_philos);
	printf("Time to die: %lld ms\n", data->time_to_die);
	printf("Time to eat: %lld ms\n", data->time_to_eat);
	printf("Time to sleep: %lld ms\n", data->time_to_sleep);
	printf("Max meals (optional): %d\n", data->max_meals);
	printf("Someone died: %d\n", data->someone_died);
	printf("Start time: %lld\n", data->start_time);

	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		printf("Philosopher %d: %p\n", i + 1, data->philos[i].left_fork);
		i++;
	}
	printf("Forks: %p\n", data->forks);
	printf("Print lock: %p\n", &data->print_lock);
	printf("Philosophers: %p\n", data->philos);
}

static int	error_exit(char *message)
{
	printf("%s\n", message);
	return (1);
}

static int	create_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL, &routine, &data->philos[i]) != 0)
		{
			printf("Error creating philosopher thread");
			return (1);
		}
		i++;
	}
	return (0);
}

static void	wait_for_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
}

void	print_meals(t_data *data)
{
	int i = 0;
	while (i < data->num_philos)
	{
		printf("id: %d, meals eaten: %d\n", data->philos[i].id, data->philos[i].meals_eaten);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	if (!parse_args(argc, argv, data))
		return (1);
	data = init_data(data);
	if (!data)
		return (error_exit("Error initializing data"));
	if (!init_forks(data))
		return (error_exit("Error initializing forks"));
	if (!init_philos(data))
		return (error_exit("Error initializing philosophers"));
	if (create_threads(data))
		return (error_exit("Error creating threads"));
	monitor_philos(data->philos, data);
	wait_for_threads(data);
	print_meals(data);
	destroy_data(data);
	return(0);
}
