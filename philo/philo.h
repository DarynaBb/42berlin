#ifndef PHILO_H
# define PHILO_H

// for memset
#include <string.h>
// for printf
#include <stdio.h>
// for malloc, free
#include <stdlib.h>
// for write, usleep
#include <unistd.h>
// for gettimeofday
#include <sys/time.h>
// for pthread_ functions
#include <pthread.h>


typedef long long	t_llong;

typedef struct s_data
{
	int				num_philos;         // Number of philosophers/forks
	t_llong			time_to_die;       // Max time a philosopher can go without eating
	t_llong			time_to_eat;       // Time it takes to eat
	t_llong			time_to_sleep;     // Time it takes to sleep
	int				max_meals;         // Optional: times each must eat
	volatile int	someone_died;      // Flag: has anyone died
	t_llong			start_time;       // Timestamp of simulation start
	pthread_mutex_t	*forks;            // Array of mutexes (forks)
	pthread_mutex_t	print_lock;       // Mutex for synchronized printing
	pthread_mutex_t	death_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t start_lock;
	pthread_mutex_t	forks_lock;
	struct s_philo	*philos;           // Array of philosopher structs

}	t_data;

typedef struct s_philo
{
	int				id;                // Philosopher number (1 to N)
	int				meals_eaten;       // How many times this philosopher has eaten
	t_llong			last_meal_time;    // Timestamp of last meal (ms)
	pthread_t		thread;            // Thread that runs this philosopher
	pthread_mutex_t	*left_fork;        // Pointer to the left fork mutex
	pthread_mutex_t	*right_fork;       // Pointer to the right fork mutex
	t_data			*data;             // Pointer to global shared data
	int				has_left_fork;
	int				has_right_fork;
	int	left_fork_available;
	int right_fork_available;
}	t_philo;

// utils
long	ft_atol(char *str);
int		is_numeric(const char *str);
void	destroy_data(t_data *data);
t_llong	get_time(void);
void	ft_usleep(long milliseconds, t_data *data);

// init
int		parse_args(int argc, char **argv, t_data *data);
t_data	*init_data(t_data *data);
int		init_philos(t_data *data);
int		init_forks(t_data *data);

// routine
int		has_someone_died(t_data *data);
void	*routine(void *arg);
void	print_action(t_philo *philo, const char *action);

// monitor
void	monitor_philos(t_philo *philos, t_data *data);

// actions
void	philo_takes_forks(t_philo *philo, t_data *data);
void	put_forks(t_philo *philo);
void	is_eating(t_philo *philo);
void	is_thinking(t_philo *philo);
void	is_sleeping(t_philo *philo);

#endif