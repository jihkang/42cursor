#include "../inc/philo.h"

void	take_fork(t_share *shr)
{
	pthread_mutex_lock(shr->l_fork);
	pthread_mutex_lock(shr->r_fork);
	print_mutex(shr->print, get_time() - shr->dur, shr->id + 1, \
		(char *)"has taken a fork");
	print_mutex(shr->print, get_time() - shr->dur, shr->id + 1, \
		(char *)"has taken a fork");
}

void	eat_meals(t_share *shr)
{
	print_mutex(shr->print, get_time() - shr->dur, shr->id + 1, \
		(char *)"is eating");
	pthread_mutex_lock(shr->data_race);
	shr->last = get_time();
	await(shr->arg->time_to_eat);
	shr->eat++;
	pthread_mutex_unlock(shr->data_race);
	pthread_mutex_unlock(shr->l_fork);
	pthread_mutex_unlock(shr->r_fork);
}

void	take_nap(t_share *shr)
{
	print_mutex(shr->print, get_time() - shr->dur, shr->id + 1, \
		(char *)"is sleeping");
	await(shr->arg->time_to_sleep);
	print_mutex(shr->print, get_time() - shr->dur, shr->id + 1, \
		"is thinkng");
}

void	print_mutex(t_mtx *mtx, t_ll time, int id, char *str)
{
	pthread_mutex_lock(mtx);
	printf("%lldms %d %s\n", time, id, str);
	pthread_mutex_unlock(mtx);
}
