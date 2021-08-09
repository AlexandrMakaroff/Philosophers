#include "philo_bonus.h"

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
	int	i;

	i = -1;
	while (++i < all->num_of_philos)
	{
		all->philos[i].pid = fork();
		if (all->philos[i].pid < 0)
			return (my_err("error: fork error"));
		else if (all->philos[i].pid == 0)
		{
			if (philosophize(&all->philos[i]))
				kill_error(all);
		}
	}
	while (1)
	{
	}
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
	sem_close(all.sema);
	sem_close(all.output);
	return (0);
}
