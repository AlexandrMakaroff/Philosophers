#include "philo_bonus.h"

static int	check_meals(t_philos *philo)
{
	if (philo->number_of_meals)
		return (1);
	return (0);
}

static void	eating(t_philos *philo)
{
	sem_wait(philo->all->sema);
	sem_wait(philo->all->sema);
	printf("%zu: philo %d has taken a fork\n", get_time(), philo->order);
	printf("%zu: philo %d is eats\n", get_time(), philo->order);
	philo->number_of_meals--;
	philo->time = get_time();
	usleep(philo->all->time_to_eat * 1000);
	sem_post(philo->all->sema);
	sem_post(philo->all->sema);
	printf("%zu: philo %d has droped a fork\n", get_time(), philo->order);
}

static void	sleeping(t_philos *philo)
{
	printf("%zu: philo %d is sleep\n", get_time(), philo->order);
	usleep(philo->all->time_to_sleep * 1000);
}

void	*time_of_death(void *philo)
{
	long		t;
	t_philos	*ph;

	ph = ((t_philos *)philo);
	t = ph->all->time_to_death;
	ph->time = get_time();
	while (get_time() - ph->time < t)
		usleep(100);
	sem_wait(ph->all->output);
	printf("%zu: philo %d is dead!\n", get_time(), ph->order);
	kill(ph->pid, SIGTERM);
	return (NULL);
}

int	philosophize(t_philos *philo)
{
	if (pthread_create(&philo->thread, NULL, time_of_death, philo))
		return (my_err("error: failed thread"));
	if (pthread_detach(philo->thread))
		return (my_err("error: failed detach thread"));
	while (1)
	{
		if (check_meals(philo))
			eating(philo);
		sleeping(philo);
		printf("%zu: philo %d is thinking\n", \
		get_time(), philo->order);
	}
	return (0);
}
