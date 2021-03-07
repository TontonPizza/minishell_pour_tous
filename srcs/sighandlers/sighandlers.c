/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sighandlers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/65 14:21:39 by vo-nguye          #+#    #+#             */
/*   Updated: 2021/03/65 14:21:39 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int		get_pid(int op, int val)
{
	static int pid;

	if(op == set)
		pid = val;
	return (pid);
}

void	sighandler_int(int signum)
{
	last_return_code(set, 128 + signum);
	write(0, "\n", 1);
	write_prompt();
}

void	sighandler_quit(int signum)
{
	if (get_pid(get, 0) < 0)
		return;
	last_return_code(set, 128 + signum);
	write(1, "exit (core dumped)\n", ft_strlen("exit (core dumped)\n"));
	exit(0);
}
