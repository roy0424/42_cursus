#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

# define ON 1
# define OFF 0

# define ERROR -1

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DEAD "died"
typedef	struct s_fork
{
	int			left;
	int			right;
}				t_fork;


typedef struct s_philo
{
	int			id;
	int			eat_cnt;
	long long	dead_time;
	pthread_t	thread_id;
	t_fork		fork;
}				t_philo;


typedef struct s_game
{
	int				philo_num;
	int				lifetime;
	int				eattime;
	int				sleeptime;
	int				eatcount;
	int				eatcount_flag;
	long long		time;
	int				index;
	int				eat;
	int				dead;
	pthread_t		manager;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	t_philo			*philo;
}					t_game;


/* parse.c */
void	parse(int argc, char **argv, t_game *p);

/* creat_thread.c */
int		create_thread(t_game *game);
void	destroy_thread(t_game *game);

/* routine.c */
void	*start_routine(void *args);
void	*manage(void *args);
void	philo_print(t_game *game, int id, char *print);

/* error.c */
void	philo_error(char *str);

/* init.c */
void	game_init(t_game *p);
void	fork_init(t_game *game);
void	philo_init(t_game *game);
void	unlock_fork(t_game *game, int i);

/* libft.c */
int	ft_atoi(const char *str);
void	free_all(t_game *game);

/* get_time.c */
long long	get_time();
long long	curr_time(long long time);

#endif