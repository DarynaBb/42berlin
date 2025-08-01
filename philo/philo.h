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

typedef struct s_data
{
	int				num_philos;         // Number of philosophers/forks
	long			time_to_die;       // Max time a philosopher can go without eating
	long			time_to_eat;       // Time it takes to eat
	long			time_to_sleep;     // Time it takes to sleep
	int				max_meals;         // Optional: times each must eat
	volatile int	someone_died;      // Flag: has anyone died
	long			start_time;        // Timestamp of simulation start

	pthread_mutex_t	*forks;            // Array of mutexes (forks)
	pthread_mutex_t	print_lock;       // Mutex for synchronized printing
	struct s_philo	*philos;           // Array of philosopher structs
}	t_data;

typedef struct s_philo
{
	int				id;                // Philosopher number (1 to N)
	int				meals_eaten;       // How many times this philosopher has eaten
	long			last_meal_time;    // Timestamp of last meal (ms)
	pthread_t		thread;            // Thread that runs this philosopher

	pthread_mutex_t	*left_fork;        // Pointer to the left fork mutex
	pthread_mutex_t	*right_fork;       // Pointer to the right fork mutex

	t_data			*data;             // Pointer to global shared data
}	t_philo;

// utils
long	ft_atol(const char *str);
int		is_numeric(const char *str);

// init
int		parse_args(int argc, char **argv, t_data *data);
t_data	*init_data(t_data *data);
int		init_philos(t_data *data);
int		init_forks(t_data *data);

#endif