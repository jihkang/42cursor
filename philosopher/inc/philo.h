#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>

typedef pthread_mutex_t	t_mtx;
typedef pthread_t		t_phd;
typedef struct timeval	t_val;
typedef long long		t_ll;

typedef struct	s_arg
{
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	eat;
	int	num;
}t_arg;

typedef struct	s_share
{
	t_mtx	*l_fork;
	t_mtx	*r_fork;
	t_mtx	*print;
	t_arg	*arg;
	int		id;
	int		state;
	int		eat;
	t_ll	last;
	t_ll	dur;
}t_share;

int		ft_atoi_pos(char *str);
void	test_argue(int ac, char **av);
t_arg	*set_arguement(int ac, char **av);
t_mtx	*set_mutex(int num);
t_share	*set_share(t_arg *arg, t_mtx *mtx, int num);
t_ll	get_time(void);
void	await(int time);
void	free_all(int num, t_mtx *mtx, t_phd *phd, t_share *shr);
void	print_philo(int num, t_share *shr);
void	print_mutex(t_mtx *mtx, t_ll time, int id, char *str);
void	take_fork(t_share *shr);
void	eat_meals(t_share *shr);
void	take_nap(t_share *shr);

#endif
