/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_manipulation_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 08:43:04 by vo-nguye          #+#    #+#             */
/*   Updated: 2021/01/08 08:43:04 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int 	env_var_count(void)
{
	int			i;
	t_env_var	*current;

	i = 0;
	current = env_list;
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}

int		destroy_env_list(t_env_var **item)
{
	if (*item == NULL)
		return (0);
	destroy_env_list(&((*item)->next));
	free((*item)->value);
	free((*item)->name);
	free(*item);
	return (0);
}

void 	destroy_env(void)
{
	if (all_env_as_array != NULL)
	{
		free_split(all_env_as_array);
		all_env_as_array = NULL;
	}
	if (requested_env_var != NULL)
	{
		free(requested_env_var);
		requested_env_var = NULL;
	}
	destroy_env_list(&env_list);
}