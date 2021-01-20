/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 02:55:51 by vo-nguye          #+#    #+#             */
/*   Updated: 2021/01/20 02:55:51 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		routine(char *command_line)
{
	t_token *first_token;
	t_token *cursor;

	first_token = 0;
	// lexer
	char **words = get_words_and_free(command_line);
	// expander
	char **words_expanded = clean_words_up_to_semicolon(words); // traite les "" '' et $ jusqu'a un ;



	print_split(words_expanded);

	free_split(words_expanded);
	return (0);
}

int main()
{
	init_env_list();

	char *line = ft_strdup("salut salut ; copain");
	routine(line);


	destroy_env();
	return (0);
}
