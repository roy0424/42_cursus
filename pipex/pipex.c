/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 08:01:51 by kyhan             #+#    #+#             */
/*   Updated: 2022/08/11 13:30:32 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
void	check(void)
{
	system("leaks a.out");
}
int	main(int argc, char **argv, char **env)
{
	atexit(check);
	t_pipex	p;

	init(&p);
	parse_argv(argc, argv, &p);
	start_execve(&p, env);
}