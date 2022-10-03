#include "../inc/philo.h"

void	check_done(t_share *shr, int *flag, int num, int eat)
{
	int	i;

	i = 0;
	if (eat <= 0)
		return ;
	while (i < num && eat > 0)
	{
		pthread_mutex_lock((shr + i)->data_race);
		if (shr[i].eat < eat)
		{
			pthread_mutex_unlock((shr + i)->data_race);
			return ;
		}
		pthread_mutex_unlock((shr + i)->data_race);
		i++;
	}
	*flag = 0;
}

void	monitor(t_share *shr, int num, int die, int eat)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (flag)
	{
		pthread_mutex_lock(shr[i].data_race);
		if (get_time() - shr[i].last > die)
		{
			pthread_mutex_unlock(shr[i].data_race);
			break;
		}
		pthread_mutex_unlock(shr[i].data_race);
		check_done(shr, &flag, num, eat);	
		i = (i + 1) % num;
	}
	pthread_mutex_lock(shr[i].print);
	if (flag == 0)
		printf("every philo eat %d times\n", eat);
	else
		printf("%lldms %d is died\n", get_time() - shr->dur, \
			(shr + i)->id + 1);
}

void	*routine(void *data)
{
	t_share	*shr;

	shr = (t_share *)data;
	while (42)
	{
		take_fork(shr);
		eat_meals(shr);
		take_nap(shr);
	}
	return (NULL);
}

void	exec(t_arg *arg)
{
	t_share	*shr;
	t_mtx	*mtx;
	t_phd	*phd;
	int		i;

	mtx = set_mutex(arg->num);
	shr = set_share(arg, mtx, arg->num);
	phd = malloc(sizeof(t_phd) * arg->num);
	i = 0;
	while (i < arg->num)
	{
		pthread_create(&phd[i], NULL, routine, (void *)&shr[i]);
		pthread_detach(phd[i]);
		i++;
	}
	monitor(shr, arg->num, arg->time_to_die, arg->eat);
	free_all(arg->num, mtx, phd, shr);
}

int	main(int ac, char **av)
{
	t_arg	*arg;

	arg = set_arguement(ac, av);
	if (arg == NULL)
		return (1);
	exec(arg);
	free(arg);
	return (0);
}
