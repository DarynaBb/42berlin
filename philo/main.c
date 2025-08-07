#include "philo.h"

void	print_data(t_data *data)
{
	if (!data)
		return;
	printf("Number of philosophers: %d\n", data->num_philos);
	printf("Time to die: %ld ms\n", data->time_to_die);
	printf("Time to eat: %ld ms\n", data->time_to_eat);
	printf("Time to sleep: %ld ms\n", data->time_to_sleep);
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

int	error_exit(char *message)
{
	printf("%s\n", message);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int		i;

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
	monitor_philos(data->philos, data);
	i = 0;
	while (i < data->num_philos)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
	printf("meals eaten: %d", data->philos->meals_eaten);
	destroy_data(data);
	return(0);
}
