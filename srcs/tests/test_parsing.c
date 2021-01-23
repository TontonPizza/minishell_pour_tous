/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 18:12:29 by vo-nguye          #+#    #+#             */
/*   Updated: 2021/01/23 18:12:29 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void test_parsing()
{
	char *line;

	get_next_line(0, &line);
	char **words = get_words_and_free(line);
	print_split(words);

}
