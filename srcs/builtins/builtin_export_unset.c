/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_unset.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/64 11:49:28 by vo-nguye          #+#    #+#             */
/*   Updated: 2021/03/64 11:49:28 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int 	is_argument_valid(char *word)
{
	int	i;

	i = 0;
	while (word[i])
	{
		if (word[i] == '+' && word[i + 1] != '=')
			return (0);
		i++;
	}
	return (1);
}

int 	export_word(char *word)
{
	char	*name;
	char	*var;
	int		i;

	name = ft_strdup(word);
	var = ft_strdup("");
	i = 0;
	while (word[i] && word[i] != '+' && word[i] != '=')
		i++;
	name[i] = 0;
	if (word[i] == '+')
	{
		free(var);
		var = (get_value_and_free_or_not(name, NO_FREE));
		i++;
	}
	i++;
	if (word[i])
		var = ft_strjoin_and_free(var, word + i);
	export_var(name, var);
	free(name);
	free(var);
	return (0);
}

int 	empty_export()
{
	char	**env_array;
	int		i;

	i = 0;
	env_array = get_env_as_array();
	while (env_array && env_array[i])
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putendl_fd(env_array[i], 1);
		i++;
	}
	return (0);
}

int 	builtin_export(char **cmd)
{
	int		i;

	i = 1;
	if (split_size(cmd) == 1)
		return (empty_export());
	while (cmd[i])
	{
		if (is_argument_valid(cmd[i]))
			export_word(cmd[i]);
		else
			generate_error("export : invalid identifier", 1);
		i++;
	}
	free_split(cmd);
	return (0);
}

int 	builtin_unset(char **cmd)
{
	int	i;

	i = 1;
	while (cmd[i])
	{
		unset_env(cmd[i]);
		i++;
	}
	free_split(cmd);
	return (0);
}
