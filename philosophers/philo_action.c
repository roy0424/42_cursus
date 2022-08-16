/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:07:51 by kyhan             #+#    #+#             */
/*   Updated: 2022/08/16 17:36:40 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_eat(t_game *game, int i)
{
	long long	eattime;

	if (i % 2 == 0)
	{
		pthread_mutex_lock(&game->fork[game->philo[i].fork.left]);
		philo_print(game, game->philo[i].id, FORK);
		pthread_mutex_lock(&game->fork[game->philo[i].fork.right]);
		philo_print(game, game->philo[i].id, FORK);
	}
	else
	{
		pthread_mutex_lock(&game->fork[game->philo[i].fork.right]);
		philo_print(game, game->philo[i].id, FORK);
		pthread_mutex_lock(&game->fork[game->philo[i].fork.left]);
		philo_print(game, game->philo[i].id, FORK);
	}
	philo_print(game, game->philo[i].id, EAT);
	game->philo[i].dead_time = get_time();
	vsleep(game->eattime);
	unlock_fork(game, i);
}

void	philo_sleep(t_game *game, int i)
{
	philo_print(game, game->philo[i].id, SLEEP);
	vsleep(game->sleeptime);
}

void	philo_think(t_game *game, int i)
{
	philo_print(game, game->philo[i].id, THINK);
}

void	philo_dead(t_game *game, int *i)
{
	long long	time;

	if (*i == game->philo_num)
		*i = 0;
	time = curr_time(game->philo[*i].dead_time);
	if (time > game->lifetime)
	{
		philo_print(game, game->philo[*i].id, DEAD);
		game->dead = ON;
	}
	i++;
}
