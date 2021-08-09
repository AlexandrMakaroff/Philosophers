#include "philo.h"

static int	check_valid_arg_fifth(char *av)
{
	int	i;

	i = -1;
	while (av[++i])
	{
		if (!ft_isdigit(av[i]))
			return (1);
	}
	return (0);
}

static int	check_valid_args(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (my_err("error: wrong number of arguments\n"));
	if (ft_atof(av[1]) < 1)
		return (my_err("error: wrong number of philosophers\n"));
	if (ft_atof(av[2]) <= 0.0)
		return (my_err("error: wrong time of death\n"));
	if (ft_atof(av[3]) <= 0.0)
		return (my_err("error: wrong time of eat\n"));
	if (ft_atof(av[4]) <= 0.0)
		return (my_err("error: wrong time of sleep\n"));
	if (ac == 6)
	{
		if (check_valid_arg_fifth(av[5]))
			return (my_err("error: wrong num of meals\n"));
	}
	return (0);
}

int	to_start(t_all *all)
{
	int		i;

	i = -1;
	all->t1 = (pthread_t *)malloc(sizeof(pthread_t) * all->num_of_philos);
	all->t2 = (pthread_t *)malloc(sizeof(pthread_t) * all->num_of_philos);
	init_mutuxes(all);
	while (++i < all->num_of_philos)
	{
		if (pthread_create(&all->t1[i], NULL, philosophize, &all->philos[i]))
			return (my_err("error: failed thread"));
		if (pthread_create(&all->t2[i], NULL, time_of_death, &all->philos[i]))
			return (my_err("error: failed thread"));
		if (pthread_detach(all->t1[i]))
			return (my_err("error: failed join thread"));
		if (pthread_detach(all->t2[i]))
			return (my_err("error: failed join thread"));
	}
	while (!all->one_is_dead)
		usleep(10);
	destroy_mutuxes(all);
	return (0);
}

int	main(int argc, char **argv)
{
	t_all	all;

	if (check_valid_args(argc, argv))
		return (1);
	if (init_all(&all, argv))
		return (1);
	if (to_start(&all))
		return (1);
	return (0);
}
