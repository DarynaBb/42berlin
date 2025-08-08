#include "philo.h"
// 5
void	print_action(t_philo *philo, const char *action)
{
	long	time;
	pthread_mutex_lock(&philo->data->print_lock);
	if (!has_someone_died(philo->data))
	{
		time = get_time() - philo->data->start_time;
		printf("%ld %d %s\n", time, philo->id, action);
	}
	pthread_mutex_unlock(&philo->data->print_lock);
}

void	*one_philo_actions(t_philo *philo, t_data *data)
{
		pthread_mutex_lock(philo->left_fork);
		print_action(philo, "has taken a fork");
		ft_usleep(philo->data->time_to_die, data);
		pthread_mutex_unlock(philo->left_fork);
		return (NULL);
}

int	has_someone_died(t_data *data)
{
	int	result;

	pthread_mutex_lock(&data->death_lock);
	result = data->someone_died;
	pthread_mutex_unlock(&data->death_lock);
	return (result);
}

static int	is_most_starving(t_philo *philo)
{
	t_data	*data;
	int		starving;
	int		left_philo_id;
	int		right_philo_id;
	t_llong	last_meal;

	data = philo->data;
	starving = 1;
	last_meal = philo->last_meal_time;
	if (philo->id == 1)
		left_philo_id = data->num_philos;
	else
		left_philo_id = philo->id - 1;
	if (philo->id == data->num_philos)
		right_philo_id = 1;
	else
		right_philo_id = philo->id + 1;
	pthread_mutex_lock(&philo->data->meal_lock);
	if (data->philos[left_philo_id - 1].last_meal_time < last_meal
		|| data->philos[right_philo_id - 1].last_meal_time < last_meal)
		starving = 0;
	pthread_mutex_unlock(&philo->data->meal_lock);
	// printf("id: %d, starving: %d\n", philo->id, starving);
	return (starving);
}


void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->num_philos == 1)
		return (one_philo_actions(philo, philo->data));
	is_thinking(philo);
	if (philo->id % 2 == 0)
		ft_usleep(1, philo->data);
	while (1)
	{
		if(has_someone_died(philo->data))
			break ;
		if (is_most_starving(philo) && philo->meals_eaten != philo->data->max_meals)
			philo_takes_forks(philo, philo->data);
		if (philo->has_left_fork && philo->has_right_fork)
		{
			is_eating(philo);
			put_forks(philo);
		}
		is_sleeping(philo);
	}
	return (NULL);
}

