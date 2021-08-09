#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>
# include <sys/types.h>
# include <signal.h>

typedef struct s_philos
{
	int				order;
	int				time_eating;
	int				l_fork;
	int				r_fork;
	int				number_of_meals;
	long			time;
	pid_t			pid;
	struct s_all	*all;
	pthread_t		thread;
}					t_philos;

typedef struct s_all
{
	int				num_of_forks;
	int				num_of_philos;
	double			time_to_death;
	double			time_to_eat;
	double			time_to_sleep;
	t_philos		*philos;
	sem_t			*sema;
	sem_t			*output;
}					t_all;

int		ft_isdigit(int c);
int		my_err(char *str);
void	kill_error(t_all *all);
long	get_time(void);
double	ft_atof(const char *str);
int		init_all(t_all *all, char **av);
int		philosophize(t_philos *philo);
void	*time_of_death(void *philo);

#endif
