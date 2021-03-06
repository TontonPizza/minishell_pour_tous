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

#include "../../minishell.h"


int 	builtin_exit(char **cmd)
{
	if (last_pipe(get, 0) == FALSE)
		return (0);
	write(1, "exit\n", 5);
	destroy_env();
	clear_error_buffer();
	if (cmd[1] != 0)
		exit(ft_atoi(cmd[1]));
	exit(0);
}