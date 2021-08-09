#include "philo_bonus.h"

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
	sem_unlink("sem");
	sem_unlink("output");
	all->sema = sem_open("sem", O_CREAT, 0644, all->num_of_forks);
	all->output = sem_open("output", O_CREAT, 0644, 1);
	if (init_philos(all, av))
		return (1);
	return (0);
}
