/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 08:16:55 by vo-nguye          #+#    #+#             */
/*   Updated: 2021/01/06 08:16:55 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main()
{
	char *cm_1[] = {"/usr/bin/ping", "-c", "2", "google.com", NULL};
	char *cm_2[] = {"/bin/grep", "packets", NULL};
	char *cm_3[] = {"/bin/grep", "0", NULL};
	char *cm_4[] = {"/usr/bin/wc", NULL};
	char **cmd_pipe[] = {cm_1, cm_2, cm_3, cm_4, NULL};

	errno = 0;
	g_stdout_copy = dup(1);

	dup2(g_stdout_copy, 2);

	execute_cmd_pipe(cmd_pipe, -1);

}