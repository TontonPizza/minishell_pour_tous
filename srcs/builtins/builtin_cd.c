/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/65 01:13:48 by vo-nguye          #+#    #+#             */
/*   Updated: 2021/03/65 01:13:48 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void 	export_var_free(char *name, char *value)
{
	export_var(name, value);
	free(value);
}

int 	builtin_cd(char **cmd)
{
	char	**split;
	int		i;

	i = 0;
	if (cmd[1] == 0)
	{
		free_split(cmd);
		return (0);
	}
	export_var_free("OLDPWD", getcwd(NULL, 500));
	split = ft_split(cmd[1], '/');
	while (cmd[0] && cmd[1] && split[i])
	{
		if (chdir(split[i]) != 0)
		{
			generate_error("No such file or directory", 2);
			free_split(cmd);
			free_split(split);
			return (-1);
		}
		i++;
	}
	export_var_free("PWD", getcwd(NULL, 500));
	return (free_split(cmd) + free_split(split));
}

int	builtin_pwd(char **cmd)
{
	char	*pwd;

	pwd = getcwd(NULL, 500);
	ft_putendl_fd(pwd, 1);
	free(pwd);
	free_split(cmd);
	return (0);
}
