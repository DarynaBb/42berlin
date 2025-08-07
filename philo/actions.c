#include "philo.h"

void	philo_takes_forks(t_philo *philo, t_data *data)
{
	if (philo->data->num_philos == 1 || has_someone_died(data))
		return ;
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		philo->has_left_fork = 1;
		print_action(philo, "has taken a left fork");
		pthread_mutex_lock(philo->right_fork);
		philo->has_right_fork = 1;
		print_action(philo, "has taken a right fork");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		philo->has_right_fork = 1;
		print_action(philo, "has taken a right fork");
		pthread_mutex_lock(philo->left_fork);
		philo->has_left_fork = 1;
		print_action(philo, "has taken a left fork");
	}
}

void	put_forks(t_philo *philo)
{
	if (philo->has_left_fork)
	{
		pthread_mutex_unlock(philo->left_fork);
		philo->has_left_fork = 0;
	}
	if (philo->has_right_fork)
	{
		pthread_mutex_unlock(philo->right_fork);
		philo->has_right_fork = 0;
	}
}

void	is_eating(t_philo *philo)
{
	if (has_someone_died(philo->data))
		return ;
		pthread_mutex_lock(&philo->data->meal_lock);
		philo->last_meal_time = get_time();  // <== ОНОВЛИТИ ПЕРШИМ
		philo->meals_eaten++;
		pthread_mutex_unlock(&philo->data->meal_lock);
		print_action(philo, "is eating");
		ft_usleep(philo->data->time_to_eat, philo->data);
}

void	is_thinking(t_philo *philo)
{
	if (has_someone_died(philo->data))
		return ;
	print_action(philo, "is thinking");
	ft_usleep(1, philo->data);
}

void	is_sleeping(t_philo *philo)
{
	if (has_someone_died(philo->data))
		return ;
	print_action(philo, "is sleeping");
	ft_usleep(philo->data->time_to_sleep, philo->data);
	is_thinking(philo);
}
