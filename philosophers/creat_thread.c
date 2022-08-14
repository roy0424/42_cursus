#include "philosophers.h"

int		create_thread(t_game *game)
{
	int	i;

	i = 0;
	game->dead = OFF;
	game->time = get_time();
	pthread_mutex_init(&game->print, NULL);
	while (i < game->philo_num)
	{
		game->index = i;
		if (pthread_create(&game->philo[i].thread_id, NULL, &start_routine, game))
			return (ERROR);
		i++;
		usleep(1000);
	}
	if (pthread_create(&game->manager, NULL, &manage, game))
		return (ERROR);
	usleep(1000);
	i = 0;
	while (i < game->philo_num)
	{
		if (pthread_join(game->philo[i].thread_id, NULL))
			return (ERROR);
		i++;
	}
	if (pthread_join(game->manager, NULL))
		return (ERROR);
	return (0);
}

void	destroy_thread(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->philo_num)
	{
		pthread_mutex_destroy(&game->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&game->print);
}