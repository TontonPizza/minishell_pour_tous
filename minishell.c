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

//void test_env();
//void test_parsing();

void test_token()
{

	t_token *item = token_constructor("hello", token_type("hello"), 0);
	t_token *cursor = item;

	token_list_add_last(&cursor, token_constructor("pouet", 0, 0));



	while (cursor)
	{
		printf("%s %d\n", cursor->token, cursor->type);
		cursor = cursor->next;
	}

	destroy_token_list(item);

}


char 	*offset_word(char **word)
{
	char *result;

	(*word) += 3;
	result = ft_strdup(*word);
	return (result);
}

int main()
{
	init_env_list();

	char *line;

	get_next_line(1, &line);

	line = expand_backslash_and_parameters(line);

	char **words = word_split(line);
	print_split(words);

}