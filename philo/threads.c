#include "philo.h"

static int	check_meals(t_philos *philo)
{
	if (philo->number_of_meals)
		return (1);
	return (0);
}

static void	eating(t_philos *philos)
{
	pthread_mutex_lock(&philos->all->forks[philos->order - 1]);
	pthread_mutex_lock(&philos->all->forks[philos->order % \
	philos->all->num_of_forks]);
	printf("%zu: philo %d has taken a fork\n", get_time(), philos->order);
	printf("%zu: philo %d is eats\n", get_time(), philos->order);
	philos->number_of_meals--;
	philos->time = get_time();
	usleep(philos->all->time_to_eat * 1000);
	pthread_mutex_unlock(&philos->all->forks[philos->order - 1]);
	pthread_mutex_unlock(&philos->all->forks[philos->order % \
	philos->all->num_of_forks]);
	printf("%zu: philo %d has droped a fork\n", get_time(), philos->order);
}

static void	sleeping(t_philos *philos)
{
	printf("%zu: philo %d is sleeping\n", get_time(), philos->order);
	usleep(philos->all->time_to_sleep * 1000);
	printf("%zu: philo %d is woke up\n", get_time(), philos->order);
}

void	*philosophize(void *philo)
{
	while (1)
	{
		if (check_meals(philo))
			eating(philo);
		sleeping(philo);
		printf("%zu: philo %d is thinking\n", \
		get_time(), ((t_philos *)philo)->order);
	}
	return (NULL);
}

void	*time_of_death(void *philo)
{
	long		t;
	t_philos	*ph;

	ph = ((t_philos *)philo);
	t = ph->all->time_to_death;
	ph->time = get_time();
	while (get_time() - ph->time <= t)
		usleep(100);
	ph->all->one_is_dead = 1;
	pthread_mutex_lock(&ph->all->forks[ph->all->num_of_forks]);
	printf("%zu: philo %d is dead!\n", get_time(), ph->order);
	return (NULL);
}
