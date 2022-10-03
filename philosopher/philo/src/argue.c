#include "../inc/philo.h"

t_arg	*set_arguement(int ac, char **av)
{
	t_arg	*arg;

	if (ac < 5 || ac > 6)
		return (NULL);
	arg = malloc(sizeof(t_arg));
	arg->num = ft_atoi_pos(av[1]);
	arg->time_to_die = ft_atoi_pos(av[2]);
	arg->time_to_eat = ft_atoi_pos(av[3]);
	arg->time_to_sleep = ft_atoi_pos(av[4]);
	arg->eat = ft_atoi_pos(av[5]);
	if (arg->num <= 0 || arg->time_to_die <= 0 || \
		arg->time_to_eat <= 0 || arg->time_to_sleep <= 0 || \
		arg->eat == -1)
	{
		free(arg);
		return (NULL);
	}
	return (arg);
}

void	test_argue(int ac, char **av)
{
	t_arg	*arg;

	arg = set_arguement(ac, av);
	if (arg == NULL)
		return ;
	printf("philos count : %d\n", arg->num);
	printf("philos die : %dms\n", arg->time_to_die);
	printf("philos eat : %dms\n", arg->time_to_eat);
	printf("philos sleep : %dms\n", arg->time_to_sleep);
	printf("philos how many eat : %d\n", arg->eat);
	free(arg);
}


t_mtx	*set_mutex(int num)
{
	t_mtx	*mtx;
	int		i;

	mtx = malloc(sizeof(t_mtx) * (num + 1));
	i = 0;
	while (i <= num + 1)
	{
		pthread_mutex_init(mtx + i, NULL);
		i++;
	}
	return (mtx);
}

t_share	*set_share(t_arg *arg, t_mtx *mtx, int num)
{
	t_share	*shr;
	int		i;

	shr = malloc(sizeof(t_share) * num);
	i = 0;
	while (i < num)
	{
		shr[i].l_fork = &mtx[i];
		shr[i].r_fork = &mtx[(i + 1) % num];
		if (i == num - 1)
		{
			shr[i].l_fork = &mtx[(i + 1) % num];
			shr[i].r_fork = &mtx[i];
		}
		shr[i].print = &mtx[num];
		shr[i].data_race = &mtx[num + 1];
		shr[i].arg = arg;
		shr[i].id = i;
		shr[i].state = 1;
		shr[i].eat = 0;
		shr[i].last = get_time();
		shr[i].dur = get_time();
		i++;
	}
	return (shr);
}
