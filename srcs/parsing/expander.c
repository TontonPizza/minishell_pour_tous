/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_token_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:17:34 by vo-nguye          #+#    #+#             */
/*   Updated: 2021/01/12 17:17:34 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/*
 *  if word is type word expand it n words
 *
 *
 *
 */

char		*expand_word(char *word)
{
	char	*result;
	int		i;

	result = x_malloc(sizeof(char) * ft_strlen(word));
	i = 0;
	while (i < ft_strlen(word))
	{
		if (word[i] == '"')
			// expand_double_quote && continue
			;
		if (word[i] == '\'')
			// expand simple_quote && continue
			;
		if (word[i] == '\\' && is_char_in_set(word[i + 1], "$\\\"\'") == 1)
			i++;
		result = join_char_and_free(result, word[i]);
		i++;
	}
	return (result);
}









