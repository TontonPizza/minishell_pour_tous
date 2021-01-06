/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd_pipe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 08:18:38 by vo-nguye          #+#    #+#             */
/*   Updated: 2021/01/06 08:18:38 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int 	is_valid(char ***cmds) // exemple
{
	// replace ENV check if file exist qnd is executable
	if (ft_strncmp(cmds[0][0], "/bin/grep", ft_strlen(cmds[0][0])) == 0)
	{
		ft_putendl_fd("command not found", g_stdout_copy);
		return (0);
	}
	return (1);

}

int 	exec_cmd(char ***cmd)
{
	// treat redirections
	execve(cmd[0][0], cmd[0], 0);
	exit(0);
}

int		exec_fork(char ***cmds, int pipe_fd)
{
	pid_t	pid;
	pid = fork();
	if (pid < 0)
		return (-1);
	if (pid == CHILD_PROCESS && close(pipe_fd) == 0)
		exec_cmd(cmds);
	return (0);
}

int 	execute_cmd_pipe(char ***cmds, int source)
{
	pid_t		pid;
	int 		pipe_fd[2];

	if (cmds[0] == NULL)
		return (close(source));
	if (pipe(pipe_fd) < 0)
		return (-1);
	if (cmds[1] == NULL) // if it's the last command of the list => output = stdout
		dup2(g_stdout_copy, 1);
	else
		dup2(pipe_fd[1], 1);
	dup2(source, 0);
	if (is_valid(cmds))
		exec_fork(cmds, pipe_fd[0]);
	else
		cmds[1] = 0;
	wait(0);
	close(pipe_fd[1]);
	close(source);
	return (execute_cmd_pipe(cmds + 1, pipe_fd[0]));
}