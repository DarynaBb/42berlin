#include "philo.h"

int	is_numeric(const char *str)
{
	int	i;
	
	i = 0;

	if (!str || !str[0])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long	ft_atol(char *str)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

void	destroy_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	free(data->forks);
	pthread_mutex_destroy(&data->print_lock);
	pthread_mutex_destroy(&data->death_lock);
	pthread_mutex_destroy(&data->meal_lock);
	if (data->philos)
		free(data->philos);
}

// long	get_time(void)
// {
// 	struct timeval	time;

// 	if (gettimeofday(&time, NULL) != 0)
// 		return (-1);
// 	return (time.tv_sec * 1000 + time.tv_usec / 1000);
// }

t_llong	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000LL + time.tv_usec / 1000LL);
}



void	ft_usleep(long milliseconds, t_data *data)
{
	long	start;

	start = get_time();
	while(get_time() - start < milliseconds)
	{
		if (has_someone_died(data))
			break;
		usleep(10);
	}
}
