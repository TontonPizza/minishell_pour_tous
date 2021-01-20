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

int		list_size(t_token *list)
{
	int i;

	i = 0;
	while(list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

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

int main_tlm() {
	t_token *first;
	char *line = ft_strdup("echo pout < caca | super x ; cat toto");
	char **words = get_words_and_free(line);
//	words_to_token_list_and_free_words(words, &first);

	print_split(words);

	return (0);
}