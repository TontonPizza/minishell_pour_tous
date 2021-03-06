/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/64 20:02:18 by vo-nguye          #+#    #+#             */
/*   Updated: 2021/03/64 20:02:18 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int 	echo_n(char **cmd)
{
	int		i;

	i = 2;
	while (cmd[i])
	{
		ft_putstr_fd(cmd[i], 1);
		i++;
	}
	return (0);
}

int echo_vanilla(char **cmd)
{
	int 	i;

	i = 1;
	while (cmd[i])
	{
		ft_putendl_fd(cmd[i], 1);
		i++;
	}
	return (0);
}


int 	builtin_echo(char **cmd)
{
	pid_t pid;

	pid = fork();
	if (pid < 0)
		return (0);
	if (pid == CHILD_PROCESS)
	{
		if (cmd[0] && cmd[1] && vo_strcmp(cmd[1], "-n") == 0)
			echo_n(cmd);
		else
			echo_vanilla(cmd);
		free_split(cmd);
		exit(0);
	}
	waitpid(0, 0, 0);
	free_split(cmd);
	return (0);
}

