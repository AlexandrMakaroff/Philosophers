#include "philo.h"

static int	init_philos(t_all *all, char **av)
{
	int	i;

	all->philos = (t_philos *)malloc(sizeof(t_philos) * all->num_of_philos);
	if (!all->philos)
		return (my_err("error: failed to allocate memory"));
	i = -1;
	while (++i < all->num_of_philos)
	{
		all->philos[i].order = i + 1;
		all->philos[i].is_eat = 0;
		all->philos[i].all = all;
		if (av[5])
			all->philos[i].number_of_meals = ft_atof(av[5]);
		else
			all->philos[i].number_of_meals = -1;
	}
	return (0);
}

int	init_all(t_all *all, char **av)
{
	all->num_of_philos = ft_atof(av[1]);
	if (all->num_of_philos > 1)
		all->num_of_forks = all->num_of_philos;
	else
		all->num_of_forks = 2;
	all->time_to_death = ft_atof(av[2]);
	all->time_to_eat = ft_atof(av[3]);
	all->time_to_sleep = ft_atof(av[4]);
	all->philos = NULL;
	all->one_is_dead = 0;
	all->meals_is_over = 0;
	all->forks = (t_mutex *)malloc(sizeof(t_mutex) * (all->num_of_forks + 1));
	if (init_philos(all, av))
		return (1);
	return (0);
}

int	init_mutuxes(t_all *all)
{
	int	i;

	i = -1;
	while (++i <= all->num_of_forks)
		pthread_mutex_init(&all->forks[i], NULL);
	return (0);
}

int	destroy_mutuxes(t_all *all)
{
	int	i;

	i = -1;
	while (++i <= all->num_of_forks)
		pthread_mutex_destroy(&all->forks[i]);
	return (0);
}
