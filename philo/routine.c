#include "philo.h"

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

// 

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->num_philos == 1)
		return (one_philo_actions(philo, philo->data));
	is_thinking(philo);
	if (philo->id % 2 == 0)
		ft_usleep(10, philo->data);
	while (1)
	{
		if(has_someone_died(philo->data))
			break ;
		philo_takes_forks(philo, philo->data);
		is_eating(philo);
		put_forks(philo);
		is_sleeping(philo);
	}
	return (NULL);
}

