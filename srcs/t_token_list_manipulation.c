/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_token_list_manipulation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 10:04:16 by vo-nguye          #+#    #+#             */
/*   Updated: 2021/01/07 10:04:16 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void 	token_add_back(t_token **list, t_token *item)
{
	t_token *current;

	if (*list == 0)
	{
		*list = item;
		return;
	}
	current = *list;
	while (current->next)
		current = current->next;
	current->next = item;
}