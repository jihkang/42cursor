#include "../inc/philo.h"

int	ft_atoi_pos(char *str)
{
	long	num;

	num = 0;
	if (str == NULL)
		return (-2);
	while (*str == ' ')
		str++;
	if (*str == '-')
		return (-1);
	if (*str == '+')
		str++;
	if (!(*str >= '0' || *str <= '9'))
		return (-1);
	while (*str >= '0' && *str <= '9')
	{
		num = (*str - '0') + num * 10;
		str++;
	}
	if (num >= 2147483648)
		return (-1);
	return (num);
}

t_ll	get_time(void)
{
	t_val	cur;

	gettimeofday(&cur, NULL);
	return (cur.tv_sec * 1000 + cur.tv_usec / 1000);
}

void	await(int time)
{
	t_ll	begin;

	begin = get_time();
	while (42)
	{
		if (get_time() - begin >= time)
			break;
		usleep(100);
	}
}

void	free_all(int num, t_mtx *mtx, t_phd *phd, t_share *shr)
{
	int	i;

	i = 0;
	while (i < num)
	{
		pthread_mutex_unlock(mtx + i);
		pthread_mutex_destroy(mtx + i);
		i++;
	}
	free(mtx);
	free(phd);
	free(shr);
}

void	print_philo(int num, t_share *shr)
{
	int	i;

	i = 0;
	while (i < num)
	{
		printf("left : %p\n", shr[i].l_fork);
		printf("right : %p\n", shr[i].r_fork);
		printf("print : %p\n", shr[i].print);
		printf("id : %d\n", shr[i].id);
		printf("start : %lld\n", shr[i].dur);
		printf("last meal : %lld\n", shr[i].last);
		printf("current eat count : %d\n", shr[i].eat);
		printf("\n\n");
		i++;
	}
}
