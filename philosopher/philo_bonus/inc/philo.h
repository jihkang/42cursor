#ifndef	PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <semaphore.h>

typedef enum	e_state
{
	HUNGRY = 1,
	THINKING = 2,
	EATING = 3,
	SLEEP = 4,
	DIE = 5,
	DONE = 6,
}t_state;

typedef struct s_arg
{
	int	num;
	int	ttd;
	int	tte;
	int	tts;
	int eat;
}t_arg;

typedef struct s_fork_info
{
	sem_t	*forks;
	sem_t	*print;
	sem_t	*lock;
}t_fork_info;

typedef struct s_philoparam
{
	t_arg		*arg;
	t_fork_info	*fork;
	int			remain;
	int			state;
}t_philoparam;

#endif
