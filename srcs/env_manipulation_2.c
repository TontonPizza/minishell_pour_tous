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

int 	env_var_count()
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