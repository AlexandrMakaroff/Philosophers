#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef pthread_mutex_t	t_mutex;

typedef struct s_philos
{
	int				order;
	int				time_eating;
	int				l_fork;
	int				r_fork;
	int				is_eat;
	int				number_of_meals;
	long			time;
	struct s_all	*all;
}					t_philos;

typedef struct s_all
{
	int				num_of_forks;
	int				num_of_philos;
	int				one_is_dead;
	int				meals_is_over;
	double			time_to_death;
	double			time_to_eat;
	double			time_to_sleep;
	t_philos		*philos;
	t_mutex			*forks;
	pthread_t		*t1;
	pthread_t		*t2;
}					t_all;

int		ft_isdigit(int c);
int		my_err(char *str);
int		init_all(t_all *all, char **av);
int		init_mutuxes(t_all *all);
int		destroy_mutuxes(t_all *all);
long	get_time(void);
double	ft_atof(const char *str);
void	*philosophize(void *philo);
void	*time_of_death(void *philo);

#endif