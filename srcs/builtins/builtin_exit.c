/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builint_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/65 01:27:15 by vo-nguye          #+#    #+#             */
/*   Updated: 2021/03/65 01:27:15 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int 	exit_code(int op, int val)
{
	static int	code;

	if (op == set)
		code = val;
	return (code);
}

int 	put_in_range(int i)
{
	while (i < 0)
		i += 256;
	while (i > 256)
		i -= 256;
	return (i);
}

int 	builtin_exit(char **cmd)
{
	if (last_pipe(get, 0) == FALSE)
	{
		free_split(cmd);
		return (0);
	}
	if (cmd[1] != 0)
	{
		if (ft_atoi(cmd[1]) < 0 || ft_atoi(cmd[1]) > 255)
			exit_code(set, put_in_range(ft_atoi(cmd[1])));
		else
			exit_code(set, ft_atoi(cmd[1]));
	}
	else
		exit_code(set, last_return_code(get, 0));
	if (cmd[0] && cmd[1] && cmd[2])
		exit_code(set, 214);
	free_split(cmd);
	return (0);
}
