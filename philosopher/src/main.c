#include "../inc/philo.h"

void	monitor(t_share *shr, int num, int die, int eat)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 1;
	while (flag)
	{
		j = 0;
		pthread_mutex_lock(shr[i].data_race);
		if (get_time() - shr[i].last > die)
			break;
		pthread_mutex_unlock(shr[i].data_race);
		while (j < num && eat > 0)
		{
			pthread_mutex_lock(shr[i].data_race);
			if (shr[j].eat < eat)
				break;
			pthread_mutex_unlock(shr[i].data_race);
			j++;
		}
		if (j == num)
			flag = 0;
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
