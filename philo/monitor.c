#include "philo.h"

void	if_died(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->death_lock);
	data->someone_died = 1;
	pthread_mutex_unlock(&data->death_lock);
	pthread_mutex_lock(&data->print_lock);
	printf("%lld %d died\n", get_time() - data->start_time, philo->id);
	pthread_mutex_unlock(&data->print_lock);
}

void	if_full(t_data *data)
{
	pthread_mutex_lock(&data->death_lock);
	data->someone_died = 1;
	pthread_mutex_unlock(&data->death_lock);
}

void	monitor_philos(t_philo *philos, t_data *data)
{
	int		i;
	long	time_since_last_meal;
	int		full_philos;

	while(!has_someone_died(data))
	{
		i = 0;
		full_philos = 0;
		while (i < data->num_philos)
		{
			pthread_mutex_lock(&data->meal_lock);
			time_since_last_meal = get_time() - philos[i].last_meal_time;
			if (time_since_last_meal >= data->time_to_die)
			{
				if_died(&philos[i], data);
				pthread_mutex_unlock(&data->meal_lock);
				return ;
			}
			if (data->max_meals != -1 && philos[i].meals_eaten >= data->max_meals)
				full_philos++;
			pthread_mutex_unlock(&data->meal_lock);
			i++;
		}
		if (data->max_meals != -1 && full_philos == data->num_philos)
		{
			if_full(data);
			return ;
		}
		// usleep(1000);
	}
}
