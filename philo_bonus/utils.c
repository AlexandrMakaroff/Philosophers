#include "philo_bonus.h"

int	my_err(char *str)
{
	printf("%s", str);
	return (EXIT_FAILURE);
}

void	kill_error(t_all *all)
{
	kill(all->philos->pid, SIGTERM);
}

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((long)(time.tv_sec * 1000 + time.tv_usec / 1000));
}
