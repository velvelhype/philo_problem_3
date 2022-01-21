#include "philo.h"

void	pre_check(t_status *s, int c)
{
	if (is_over(s))
		return ;
	if (s->max == 3)
		lock_mutex(s, c);
}

void	lock_mutex(t_status *s, int c)
{
	pthread_mutex_lock(&s->fork_mutex[fork_cnt(c, s->max)]);
	pthread_mutex_lock(&s->fork_mutex[fork_cnt(c + 1, s->max)]);
}

void	unlock_mutex(t_status *s, int c)
{
	pthread_mutex_unlock(&s->fork_mutex[fork_cnt(c, s->max)]);
	pthread_mutex_unlock(&s->fork_mutex[fork_cnt(c + 1, s->max)]);
}
